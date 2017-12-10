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
extern double _rssi_to_dist(double rssi);


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
    ellipse = scene.addEllipse(0, 0, 15, 15, blackPen, redBrush);
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
       /*
       qDebug("[pi0] %f", (signed int)packetshm[0].rssi - 256.0  );
       qDebug("[pi1] %f", (signed int)packetshm[1].rssi - 256.0  );
       qDebug("[pi2] %f", (signed int)packetshm[2].rssi - 256.0  );
*/
       KalmanPredictUpdate1D(&kalman_filter[0], (signed int)packetshm[0].rssi - 256.0 );
       KalmanPredictUpdate1D(&kalman_filter[1], (signed int)packetshm[1].rssi - 256.0 );
       KalmanPredictUpdate1D(&kalman_filter[2], (signed int)packetshm[2].rssi - 256.0 );

       /*
       qDebug() << "Hello";

       qDebug("rssi 00 = %f",  kalman_filter[0].X);
       qDebug("rssi 01 = %f",  kalman_filter[1].X);
       qDebug("rssi 02 = %f",  kalman_filter[2].X);
*/
       qDebug("dist 0 = %f",  _rssi_to_dist(kalman_filter[0].X));
       qDebug("dist 1 = %f",  _rssi_to_dist(kalman_filter[1].X));
       qDebug("dist 2 = %f",  _rssi_to_dist(kalman_filter[2].X));
/*
       c[0].a = device_x_pos[0]*cm_per_pixel/100.0;
       c[1].a = device_x_pos[1]*cm_per_pixel/100.0;
       c[2].a = device_x_pos[2]*cm_per_pixel/100.0;

       c[0].b = device_y_pos[0]*cm_per_pixel/100.0;
       c[1].b = device_y_pos[1]*cm_per_pixel/100.0;
       c[2].b = device_y_pos[2]*cm_per_pixel/100.0;

       //qDebug("(%.2f,%.2f), (%.2f,%.2f), (%.2f,%.2f) ",
       //       c[0].a, c[0].b, c[1].a, c[1].b, c[2].a, c[2].b);

       c[0].k = kalman_filter[0].X;
       c[1].k = kalman_filter[1].X;
       c[2].k = kalman_filter[2].X;

       _solve_position(c, &predicted_dot);

       predicted_dot.x = predicted_dot.x*100/cm_per_pixel;
       predicted_dot.y = predicted_dot.y*100/cm_per_pixel;

       if (predicted_dot.x < 10.0 ) predicted_dot.x = 10.0;
       else if (predicted_dot.x > 740.0 ) predicted_dot.x = 740.0;
       if (predicted_dot.y < 10.0 ) predicted_dot.y = 10.0;
       else if (predicted_dot.x > 740.0 ) predicted_dot.x = 740.0;

//       qDebug("now new position is ... x = %d  y = %d", (signed int)predicted_dot.x, (signed int)predicted_dot.y);
       ellipse->setPos((signed int)predicted_dot.x,(signed int)predicted_dot.y);
*/
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
