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

extern QString selectedMapPath;
extern Packet * packetshm;

extern void KalmanPredictUpdate1D(SKalman1D *kalman, double NewData);
extern void _solve_line(_circle c1, _circle c2, _line * l);
extern void _solve_dot(_line l1, _line l2, _dot * d);
extern void _solve_position(_circle * circle, _dot * ans);
extern void _solve_position(_circle * circle, _dot * ans);


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
    ellipse = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
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

       qDebug("[pi0      w]received rssi value is....%d" , ((signed int)packetshm[0].rssi | 0xffffff00)  );
//       qDebug("[pi1 case o]received rssi value is....%d" , ((signed int)packetshm[1].rssi | 0xffffff00)  );
//       qDebug("[pi1 case x]received rssi value is....%d" , ((signed int)packetshm[2].rssi | 0xffffff00)  );



       /* ############## sample codes of trisol. ###################
       _circle c[3] = { { 0, 0, 1 }, { 1, 4, 1 }, { 2, 0, 1 } };
       _dot d;
       _solve_position(c, &d);
       qDebug("x = %.2f\ny = %.2f", d.x, d.y);
       */

       /* ############## sample codes of kfsol. ####################
       double sample[100];
       for (int i = 0; i < 100; i++)
           sample[i] = (-10 + rand() % 201/10.0 );
           //sample[i] = i>50?50:i;

       SKalman1D kalman;
       kalman.X = 0;
       kalman.Q = 10;
       kalman.P = 10;
       kalman.R = 200;

       printf("now position = %.2f \n", kalman.X);
       for (int i = 0; i < 100; i++) {
           KalmanPredictUpdate1D(&kalman, sample[i]);
           qDebug("now pos = %6.2f, real pos = %6.2f \n", kalman.X, sample[i]);
       }
       */

       get_x_pos = 80.0 + (double)(rand()%41);
       get_y_pos = 180.0+ (double)(rand()%41);
       ellipse->setPos(get_x_pos,get_y_pos);
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
