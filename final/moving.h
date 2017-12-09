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
#include <QGraphicsItem>
#include "kfsol.h"


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

public slots:
    void shmchk(void);

private slots:
   void on_horizontalSlider_valueChanged(int value);
   void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MOVING *ui;
    QGraphicsScene scene;
    QGraphicsEllipseItem *ellipse;
    bool Pressed;
    qreal totalScaleFactor;
    double beforeZoom;
    double nowZoom;
    double result_x_pos;
    double result_y_pos;
    signed int tx_power[3] = {-44,-59,-59};
    signed int rssi_buf[3];
    double kalman_filtered_dist[3] = {1,1,1};
    SKalman1D kalman_filter[3] = {
        {1,10,50,500},
        {12,10,10,100},
        {13,10,10,100},
    };

protected:
//    virtual void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool viewportEvent(QEvent *event);
 //   void mouseGrabber();
    void mouseMoveEvent(QMouseEvent * evet);
//    bool eventFilter(QObject *object, QEvent *event);


};

#endif // MOVING_H
