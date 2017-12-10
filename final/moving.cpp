#include "moving.h"
#include "ui_moving.h"
#include <QScrollBar>
#include <QTouchEvent>
#include "shm.h"
#include "kfsol.h"
#include "trisol.h"
#include <QTimer>
#include <stdio.h>
#include "mapsettings.h"
#include "ui_mapsettings.h"

extern _circle c[3];
extern _dot predicted_dot;
extern SKalman1D kalman_filter[3];
extern signed int tx_power[3];
extern signed int device_x_pos[3];
extern signed int device_y_pos[3];
extern double cm_per_pixel;

extern QString selectedMapPath;
extern Packet * packetshm;

extern void KalmanPredictUpdate1D(SKalman1D *kalman, double NewData);
extern void _solve_line(_circle c1, _circle c2, _line * l);
extern void _solve_dot(_line l1, _line l2, _dot * d);
extern void _solve_position(_circle * circle, _dot * ans);
extern void _solve_position(_circle * circle, _dot * ans);
extern double _rssi_to_dist(signed int rssi, signed int tx);


MOVING::MOVING(QWidget *parent) :
    QDialog(parent),totalScaleFactor(1),
    ui(new Ui::MOVING)
{
    ui->setupUi(this);

    nowZoom = 100.0;

    Pressed=false;

    QPixmap pix(selectedMapPath);
    scene.addPixmap(pix);


    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    ellipse = scene.addEllipse(180, 100, 15, 15, blackPen, redBrush);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
//   ellipse->setPos(200,200);
//  ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//  ui->graphicsView->setViewport(this);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
//  ui->graphicsView->s
//  ui->graphicsView->setAttribute(Qt::WA_AcceptTouchEvents);
//  this->setCursor(Qt::BlankCursor);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->horizontalSlider->setValue(50);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(shmchk()));
    timer->start(1280);
}

void MOVING::shmchk(void)
{
   if(packetshm != NULL)
   {

       //qDebug("[pi0 w] received rssi value is....%d" , ((signed int)packetshm[0].rssi | 0xffffff00)  );
       //qDebug("[pi1 o] received rssi value is....%d" , ((signed int)packetshm[1].rssi | 0xffffff00)  );
       //qDebug("[pi1 x] received rssi value is....%d" , ((signed int)packetshm[2].rssi | 0xffffff00)  );

       qDebug("dist 0 = %f", _rssi_to_dist(((signed int)packetshm[0].rssi | 0xffffff00), tx_power[0]) );
       qDebug("dist 1 = %f", _rssi_to_dist(((signed int)packetshm[1].rssi | 0xffffff00), tx_power[1]) );
       qDebug("dist 2 = %f", _rssi_to_dist(((signed int)packetshm[2].rssi | 0xffffff00), tx_power[2]) );

       c[0].a = device_x_pos[0]*cm_per_pixel/100.0;
       c[1].a = device_x_pos[1]*cm_per_pixel/100.0;
       c[2].a = device_x_pos[2]*cm_per_pixel/100.0;

       c[0].b = device_y_pos[0]*cm_per_pixel/100.0;
       c[1].b = device_y_pos[1]*cm_per_pixel/100.0;
       c[2].b = device_y_pos[2]*cm_per_pixel/100.0;

       c[0].k = _rssi_to_dist(((signed int)packetshm[0].rssi | 0xffffff00), tx_power[0]);
       c[1].k = _rssi_to_dist(((signed int)packetshm[1].rssi | 0xffffff00), tx_power[1]);
       c[2].k = _rssi_to_dist(((signed int)packetshm[2].rssi | 0xffffff00), tx_power[2]);

       _solve_position(c, &predicted_dot);

       predicted_dot.x = predicted_dot.x*100/cm_per_pixel;
       predicted_dot.y = predicted_dot.y*100/cm_per_pixel;

       qDebug("now position is ... x = %.2f\ny = %.2f", predicted_dot.x, predicted_dot.y);

       ellipse->setPos((unsigned int)predicted_dot.x,(unsigned int)predicted_dot.y);
   }
}

MOVING::~MOVING()
{
    delete ui;
}


void MOVING::mousePressEvent(QMouseEvent *event)
{
    //qDebug() << "pressed";
    Pressed=true;
    update();
    mx = event->pos().x();
    my = event->pos().y();
    qDebug() << mx;
    qDebug() << my;
}

void MOVING::mouseMoveEvent(QMouseEvent * event)
{
    //ui->graphicsView->NoAnchor;

//    ui->graphicsView->move(event->globalX()-mx,event->globalY()-my);
    //translate(event->globalX()-mx,event->globalY()-my);

    qDebug() << event->globalX();
    qDebug() << event->globalY();
}

void MOVING::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "released";
    Pressed=false;
    update();
}


void MOVING::on_horizontalSlider_valueChanged(int value)
{
    beforeZoom = nowZoom;
    nowZoom = 50.0+1.0*value;
    ui->graphicsView->scale(nowZoom/beforeZoom, nowZoom/beforeZoom);
}

void MOVING::on_horizontalSlider_sliderMoved(int value)
{
    beforeZoom = nowZoom;
    nowZoom = 50.0+1.0*value;
    ui->graphicsView->scale(nowZoom/beforeZoom, nowZoom/beforeZoom);
}


void MOVING::on_pushButton_clicked()
{
    close();
}
