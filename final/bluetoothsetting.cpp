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
    ui->setupUi(this);
    QPixmap pix(selectedMapPath);
    scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    ui->groupBox->setStyleSheet("font-weight: bold;");
    ui->Device_Label->setStyleSheet("font-weight: bold;");
    ui->X_Label->setStyleSheet("font-weight: bold;");
    ui->Y_Label->setStyleSheet("font-weight: bold;");
    ui->D_Label->setStyleSheet("font-weight: bold;");
    ui->T_Label->setStyleSheet("font-weight: bold;");
    ui->P_Label->setStyleSheet("font-weight: bold;");
    ui->Q_Label->setStyleSheet("font-weight: bold;");
    ui->R_Label->setStyleSheet("font-weight: bold;");
    ui->Device_Label->setAlignment(Qt::AlignRight);
    ui->X_Label->setAlignment(Qt::AlignRight);
    ui->Y_Label->setAlignment(Qt::AlignRight);
    ui->D_Label->setAlignment(Qt::AlignRight);
    ui->T_Label->setAlignment(Qt::AlignRight);
    ui->P_Label->setAlignment(Qt::AlignRight);
    ui->Q_Label->setAlignment(Qt::AlignRight);
    ui->R_Label->setAlignment(Qt::AlignRight);
    ui->label_14->setAlignment(Qt::AlignRight);
    ui->label_15->setAlignment(Qt::AlignRight);
    ui->label_16->setAlignment(Qt::AlignRight);
    ui->zero_d->setAlignment(Qt::AlignRight);
    ui->zero_p->setAlignment(Qt::AlignRight);
    ui->zero_q->setAlignment(Qt::AlignRight);
    ui->zero_r->setAlignment(Qt::AlignRight);
    ui->zero_t->setAlignment(Qt::AlignRight);
    ui->zero_x->setAlignment(Qt::AlignRight);
    ui->zero_y->setAlignment(Qt::AlignRight);
    ui->one_d->setAlignment(Qt::AlignRight);
    ui->one_p->setAlignment(Qt::AlignRight);
    ui->one_q->setAlignment(Qt::AlignRight);
    ui->one_r->setAlignment(Qt::AlignRight);
    ui->one_t->setAlignment(Qt::AlignRight);
    ui->one_x->setAlignment(Qt::AlignRight);
    ui->one_y->setAlignment(Qt::AlignRight);
    ui->two_d->setAlignment(Qt::AlignRight);
    ui->two_p->setAlignment(Qt::AlignRight);
    ui->two_q->setAlignment(Qt::AlignRight);
    ui->two_r->setAlignment(Qt::AlignRight);
    ui->two_t->setAlignment(Qt::AlignRight);
    ui->two_x->setAlignment(Qt::AlignRight);
    ui->two_y->setAlignment(Qt::AlignRight);
    memset(chkEllipse, 0, sizeof(chkEllipse));
    msgboxchk = 0;
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
        qDebug("val : %d", chkEllipse[0]);

        if(chkEllipse[0] == 0)
        {
            chkEllipse[0] = 1;
            QBrush redBrush(Qt::red);
            QPen blackPen(Qt::black);
            qDebug() << "before ellipse0";
            ellipse0 = scene.addEllipse(mx, my, 15, 15, blackPen, redBrush);
            qDebug() << "after ellipse0" << ellipse0;
            ui->zero_x->setText(QString::number(mx));
            ui->zero_y->setText(QString::number(my));
        }
        else
        {
            qDebug() << "else";
            ellipse0->setRect(QRectF(0, 0, 15, 15));
            ellipse0->setPos(mx, my);
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
            ellipse1 = scene.addEllipse(mx, my, 15, 15, blackPen, blueBrush);
            qDebug() << "ellipse1 "<<  ellipse1;
            ui->one_x->setText(QString::number(mx));
            ui->one_y->setText(QString::number(my));
        }
        else
        {
             qDebug() << "else ellipse1 "<<  ellipse1;
             ellipse1->setRect(QRectF(0, 0, 15, 15));
             ellipse1->setPos(mx, my);
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
            ellipse2 = scene.addEllipse(mx, my, 15, 15, blackPen, greenBrush);
            ui->two_x->setText(QString::number(mx));
            ui->two_y->setText(QString::number(my));
        }
        else
        {
            ellipse2->setRect(QRectF(0, 0, 15, 15));
            ellipse2->setPos(mx, my);
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
        msgBox.exec();
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
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
 //       msgBox.exec();
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
 //       msgBox.exec();
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
 //       msgBox.exec();
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
 //       msgBox.exec();
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
 //       msgBox.exec();
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
  //      msgBox.exec();
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
  //      msgBox.exec();
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
 //       msgBox.exec();
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
 //       msgBox.exec();
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
//        msgBox.exec();
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
 //       msgBox.exec();
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
 //       msgBox.exec();
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
    QMessageBox msgBox;
    msgBox.setText("The value has successfully changed.");
    msgBox.exec();
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
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
 //       msgBox.exec();
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
 //       msgBox.exec();
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
  //      msgBox.exec();
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
