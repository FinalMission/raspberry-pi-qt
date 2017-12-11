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
     Ui::MOVING *ui;
    QGraphicsScene scene;
    QGraphicsEllipseItem * ellipse;
    QGraphicsEllipseItem * ellipseDst;
    QGraphicsRectItem * rectangle[100000];
public slots:
    void shmchk(void);

private slots:
   void on_horizontalSlider_valueChanged(int value);
   void on_horizontalSlider_sliderMoved(int position);

   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void on_checkBox_clicked(bool checked);

   void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

private:
    bool Pressed;
    qreal totalScaleFactor;
    double beforeZoom;
    double nowZoom;
    double get_x_pos;
    double get_y_pos;

protected:
//    virtual void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool viewportEvent(QEvent *event);
 //   void mouseGrabber();
    void mouseMoveEvent(QMouseEvent * evet);
//    bool eventFilter(QObject *object, QEvent *event);


};

#endif // MOVING_H
