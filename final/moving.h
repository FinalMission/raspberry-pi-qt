#ifndef MOVING_H
#define MOVING_H

#include <QDialog>
#include <QGraphicsView>
#include <QPixmap>
#include <QDebug>
#include <QtGui>
#include <QtCore>



namespace Ui {
class MOVING;
}

class MOVING : public QDialog
{
    Q_OBJECT
    
public:
    explicit MOVING(QWidget *parent = 0);
    ~MOVING();

    
private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MOVING *ui;
    QGraphicsScene scene;
    QGraphicsEllipseItem *ellipse;
};

#endif // MOVING_H
