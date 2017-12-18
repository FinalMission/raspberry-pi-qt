#ifndef BLUETOOTHSETTING_H
#define BLUETOOTHSETTING_H

#include <QDialog>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class bluetoothSetting;
}

class bluetoothSetting : public QDialog
{
    Q_OBJECT
    
public:
    explicit bluetoothSetting(QWidget *parent = 0);
    ~bluetoothSetting();
    QGraphicsEllipseItem * ellipse0;
    QGraphicsEllipseItem * ellipse1;
    QGraphicsEllipseItem * ellipse2;
    int chkEllipse[3];
    int msgboxchk;
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

 //   void on_PiZeroW_toggled(bool checked);

    void on_pushButton_6_clicked();

private:
    Ui::bluetoothSetting *ui;
    QGraphicsScene scene;
    char ValueCharString[256];

protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // BLUETOOTHSETTING_H
