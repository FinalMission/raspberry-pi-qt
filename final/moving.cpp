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

//     qDebug() << "received packet addr is... " << *(int *)&packetshm[0];
       qDebug("[pi0      w]received rssi value is....%d" , ((signed int)packetshm[0].rssi | 0xffffff00)  );
//       qDebug("[pi1 case o]received rssi value is....%d" , ((signed int)packetshm[1].rssi | 0xffffff00)  );
//       qDebug("[pi1 case x]received rssi value is....%d" , ((signed int)packetshm[2].rssi | 0xffffff00)  );
       //trisol(packetshm);
       //
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

