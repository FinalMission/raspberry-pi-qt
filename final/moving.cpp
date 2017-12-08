#include "moving.h"
#include "ui_moving.h"
#include <QScrollBar>
#include <QTouchEvent>


MOVING::MOVING(QWidget *parent) :
    QDialog(parent),totalScaleFactor(1),
    ui(new Ui::MOVING)
{
    ui->setupUi(this);

    nowZoom = 100.0;

    Pressed=false;
    QPixmap pix(":/img/9thfloor2.png");
    scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    ellipse = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
    ellipse->setPos(200,200);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  //  ui->graphicsView->setViewport(this);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
  //  ui->graphicsView->s
//    ui->graphicsView->setAttribute(Qt::WA_AcceptTouchEvents);
//    this->setCursor(Qt::BlankCursor);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->horizontalSlider->setValue(50);


}

MOVING::~MOVING()
{
    delete ui;
}
/*
void MOVING::wheelEvent(QWheelEvent *event)
{
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
           // Scale the view / do the zoom
           double scaleFactor = 1.15;

           if(event->delta() > 0)
           {
               // Zoom in
               ui->graphicsView-> scale(scaleFactor, scaleFactor);
           }

           else
           {
               // Zooming out
                ui->graphicsView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
           }
}*/
/*
bool MOVING::eventFilter(QObject *object, QEvent *event)
{

   if (event->type() == QEvent::MouseMove)
   {
        mousePressEvent((QMouseEvent*)event);
        mouseMoveEvent((QMouseEvent*)event);
   }
   else if (event->type() == QEvent::Wheel)
   {
//       wheelEvent((QWheelEvent*)event);
   }

   if (event->type() == QEvent::TouchBegin || event->type() == QEvent::TouchUpdate || event->type() == QEvent::TouchEnd)
   {
       QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
       QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();
       if (touchPoints.count() == 2) {
           // determine scale factor
           const QTouchEvent::TouchPoint &touchPoint0 = touchPoints.first();
           const QTouchEvent::TouchPoint &touchPoint1 = touchPoints.last();
           qreal currentScaleFactor = QLineF(touchPoint0.pos(), touchPoint1.pos()).length() / QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();
           if (touchEvent->touchPointStates() & Qt::TouchPointReleased)
           {
               // if one of the fingers is released, remember the current scale
               // factor so that adding another finger later will continue zooming
               // by adding new scale factor to the existing remembered value.
               //currentScale *= currentScaleFactor;
               currentScaleFactor = 1;
           }
           ui->graphicsView->scale(currentScaleFactor, currentScaleFactor);
       }
       return true;
   }
   Q_UNUSED(object)
   return false;
}
*/
/*
bool MOVING::viewportEvent(QEvent *event)
{
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
    switch (event->type()) {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();
        if (touchPoints.count() == 2) {
            // determine scale factor
            const QTouchEvent::TouchPoint &touchPoint0 = touchPoints.first();
            const QTouchEvent::TouchPoint &touchPoint1 = touchPoints.last();
            qreal currentScaleFactor =
                    QLineF(touchPoint0.pos(), touchPoint1.pos()).length()
                    / QLineF(touchPoint0.startPos(), touchPoint1.startPos()).length();
            if (touchEvent->touchPointStates() & Qt::TouchPointReleased) {
                // if one of the fingers is released, remember the current scale
                // factor so that adding another finger later will continue zooming
                // by adding new scale factor to the existing remembered value.
                totalScaleFactor *= currentScaleFactor;
                currentScaleFactor = 1;
            }
            ui->graphicsView->scale(1*currentScaleFactor, 1*currentScaleFactor);
        }
        return true;
    }
    default:
        break;
    }
    return MOVING::viewportEvent(event);
}
*/

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
    printf("hello %d \n", value);

    beforeZoom = nowZoom;
    nowZoom = 50.0+1.0*value;

    ui->graphicsView->scale(nowZoom/beforeZoom, nowZoom/beforeZoom);
}

