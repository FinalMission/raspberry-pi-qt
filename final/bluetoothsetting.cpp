#include "bluetoothsetting.h"
#include "ui_bluetoothsetting.h"
#include <QTouchEvent>
#include "virtualkeyboard.h"
#include <QMessageBox>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <string.h>
#include <QDebug>
#include "kfsol.h"
#include "trisol.h"

extern QString selectedMapPath;
extern SKalman1D kalman_filter[3];
extern signed int tx_power[3];
extern signed int device_x_pos[3];
extern signed int device_y_pos[3];

bluetoothSetting::bluetoothSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bluetoothSetting)
{
    QPixmap pix(selectedMapPath);
    scene.addPixmap(pix);
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
}

bluetoothSetting::~bluetoothSetting()
{
    qDebug()<<"bluetoothsetting: " << ValueCharString;
    memset(ValueCharString, NULL, sizeof(ValueCharString));
    qDebug()<<"bluetoothsetting: " << ValueCharString;
    delete ui;
}

void bluetoothSetting::mousePressEvent(QMouseEvent *event)
{
    int mx, my;
    mx = event->pos().x();
    my = event->pos().y();
    if(mx <= 0 || mx >= 750 || my <= 0 || my >= 351) {
        qDebug() << "out";
        return;
    }
    qDebug("run. (%d,%d)", mx, my);

    if(ui->PiZeroW->isChecked())
    {
        if(chkEllipse[0] == 0)
        {
            chkEllipse[0] = 1;
            QBrush redBrush(Qt::red);
            QPen blackPen(Qt::black);
            ellipse0 = scene.addEllipse(mx-15, my-15, 15, 15, blackPen, redBrush);
            ui->zero_x->setText(QString::number(mx));
            ui->zero_y->setText(QString::number(my));
        }
        else
        {
            ellipse0->setRect(QRectF(0, 0, 15, 15));
            ellipse0->setPos(mx-15, my-15);
            ui->zero_x->setText(QString::number(mx));
            ui->zero_y->setText(QString::number(my));
        }
        device_x_pos[0] = mx;
        device_y_pos[0] = my;
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        if(chkEllipse[1] == 0)
        {
            chkEllipse[1] = 1;
            QBrush blueBrush(Qt::blue);
            QPen blackPen(Qt::black);
            ellipse1 = scene.addEllipse(mx-15, my-15, 15, 15, blackPen, blueBrush);
            qDebug() << "ellipse1 "<<  ellipse1;
            ui->one_x->setText(QString::number(mx));
            ui->one_y->setText(QString::number(my));
        }
        else
        {
             qDebug() << "else ellipse1 "<<  ellipse1;
             ellipse1->setRect(QRectF(0, 0, 15, 15));
             ellipse1->setPos(mx-15, my-15);
             ui->one_x->setText(QString::number(mx));
             ui->one_y->setText(QString::number(my));
        }
        device_x_pos[1] = mx;
        device_y_pos[1] = my;
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        if(chkEllipse[2] == 0)
        {
            chkEllipse[2] = 1;
            QBrush greenBrush(Qt::green);
            QPen blackPen(Qt::black);
            ellipse2 = scene.addEllipse(mx-15, my-15, 15, 15, blackPen, greenBrush);
            ui->two_x->setText(QString::number(mx));
            ui->two_y->setText(QString::number(my));
        }
        else
        {
            ellipse2->setRect(QRectF(0, 0, 15, 15));
            ellipse2->setPos(mx-15, my-15);
            ui->two_x->setText(QString::number(mx));
            ui->two_y->setText(QString::number(my));
        }
        device_x_pos[2] = mx;
        device_y_pos[2] = my;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
//        msgBox.exec();
        msgboxchk = 1;
    }
    if(msgboxchk == 0)
    {
        QMessageBox msgBox;
        msgBox.setText("Bluetooth location setting completed.");
//        msgBox.exec();
    }
    msgboxchk = 0;
}

void bluetoothSetting::on_pushButton_2_clicked()
{
    VirtualKeyboard dlg;
 //   dlg.setGeometry(300, 300, 400, 400);
    qDebug() << "bluetoothsetting: " << ValueCharString;
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);

        kalman_filter[0].X = value;
        printf("%f\n", value);
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
//        msgBox.exec();
        ui->zero_d->setText(QString::number(value));
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[1].X = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
//        msgBox.exec();
        ui->one_d->setText(QString::number(value));
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[2].X = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
  //      msgBox.exec();
        ui->two_d->setText(QString::number(value));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
    qDebug()<<"bluetoothsetting: " << ValueCharString;
}

void bluetoothSetting::on_pushButton_clicked()
{
    char ValueCharString[256];
    VirtualKeyboard dlg;
//    dlg.setGeometry(300, 300, 400, 400);
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[0].Q = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->zero_q->setText(QString::number(value));
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
         kalman_filter[1].Q = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->one_q->setText(QString::number(value));

    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[2].Q = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->two_q->setText(QString::number(value));

    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
}

void bluetoothSetting::on_pushButton_3_clicked()
{
    char ValueCharString[256];
    VirtualKeyboard dlg;
 //   dlg.setGeometry(300, 300, 400, 400);
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[0].P = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->zero_p->setText(QString::number(value));
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[1].P = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->one_p->setText(QString::number(value));

    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[2].P = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->two_p->setText(QString::number(value));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
}

void bluetoothSetting::on_pushButton_4_clicked()
{
    char ValueCharString[256];
    VirtualKeyboard dlg;
//    dlg.setGeometry(300, 300, 400, 400);
    if(ui
            ->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[0].R = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->zero_r->setText(QString::number(value));
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[1].R = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->one_r->setText(QString::number(value));
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        kalman_filter[2].R = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->two_r->setText(QString::number(value));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
}

void bluetoothSetting::on_pushButton_5_clicked()
{
    close();
}


void bluetoothSetting::on_pushButton_6_clicked()
{
    VirtualKeyboard dlg;
 //   dlg.setGeometry(300, 300, 400, 400);
 //   qDebug() << "bluetoothsetting: " << ValueCharString;
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        tx_power[0] = value;
        printf("%f\n", value);
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->zero_t->setText(QString::number(value));
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        tx_power[1] = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->one_t->setText(QString::number(value));
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        tx_power[2] = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
        ui->two_t->setText(QString::number(value));
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
    qDebug()<<"bluetoothsetting: " << ValueCharString;
}
