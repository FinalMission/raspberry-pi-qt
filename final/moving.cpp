#include "moving.h"
#include "ui_moving.h"
#include <QScrollBar>
#include <QTouchEvent>
#include "shm.h"
#include "trisol.h"
#include <QTimer>
#include <stdio.h>
#include <math.h>
#include "kfsol.h"

extern void KalmanPredictUpdate1D(SKalman1D *, double);
extern Packet * packetshm;

MOVING::MOVING(QWidget *parent) :
    QDialog(parent),totalScaleFactor(1),
    ui(new Ui::MOVING)
{
    ui->setupUi(this);

    nowZoom = 100.0;

    Pressed=false;
 //   QPixmap pix(":/img/9thfloor.png");
 //   scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    ellipse = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
    ellipse->setPos(200,200);
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
       //qDebug("filter ~ %f", kalman_filter.X);
       //qDebug("[pi0      w]received rssi value is....%d" , ((signed int)packetshm[0].rssi | 0xffffff00)  );

       rssi_buf[0] = ((signed int)packetshm[0].rssi | 0xffffff00);
       rssi_buf[1] = ((signed int)packetshm[1].rssi | 0xffffff00);
       rssi_buf[2] = ((signed int)packetshm[2].rssi | 0xffffff00);

       KalmanPredictUpdate1D( &kalman_filter[0], pow(10, (tx_power[0] - rssi_buf[0])/20.0) );

       qDebug("BLE[0] distance : %.2f m !!", kalman_filter[0].X );

        //qDebug("BLE[0] distance : %.2f m !!", pow(10, (tx_power[0] - rssi_buf[0])/20.0) );
       //qDebug("BLE[2] distance : %.2f m !!", pow(10, (tx_power[2] - rssi_buf[2])/20.0) );

       result_x_pos = 80.0 + (double)(rand()%41);
       result_y_pos = 180.0+ (double)(rand()%41);
       ellipse->setPos(result_x_pos,result_y_pos);
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
