#ifndef MOVING_H
#define MOVING_H

#include <QDialog>
#include <QGraphicsView>
#include <QPixmap>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QMouseEvent>
#include <QWidget>
#include <QWheelEvent>
#include <QGraphicsScene>



namespace Ui {
class MOVING;
}

class MOVING : public QDialog
{
    Q_OBJECT
    
public:
    explicit MOVING(QWidget *parent = 0);
    ~MOVING();
    int mx,my;
  //  bool viewportEvent(QEvent *event);

private slots:


private:
    Ui::MOVING *ui;
    QGraphicsScene scene;
    QGraphicsEllipseItem *ellipse;
    bool Pressed;
    qreal totalScaleFactor;
protected:
//    virtual void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);

 //   void mouseGrabber();
    void mouseMoveEvent(QMouseEvent * event);
//    bool eventFilter(QObject *object, QEvent *event);

};

#endif // MOVING_H
