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
extern QString selectedMapPath;
extern double PiZero_X_value;
extern double PiOneCaseO_X_value;
extern double PiOneCaseX_X_value;
extern double PiZero_Q_value;
extern double PiOneCaseO_Q_value;
extern double PiOneCaseX_Q_value;
extern double PiZero_P_value;
extern double PiOneCaseO_P_value;
extern double PiOneCaseX_P_value;
extern double PiZero_R_value;
extern double PiOneCaseO_R_value;
extern double PiOneCaseX_R_value;

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
            ellipse0 = scene.addEllipse(mx-40, my-35, 15, 15, blackPen, redBrush);
        }
        else
        {
            ellipse0->setRect(QRectF(0, 0, 15, 15));
            ellipse0->setPos(mx-40, my-35);
        }
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        if(chkEllipse[1] == 0)
        {
            chkEllipse[1] = 1;
            QBrush blueBrush(Qt::blue);
            QPen blackPen(Qt::black);
            ellipse1 = scene.addEllipse(mx-40, my-35, 15, 15, blackPen, blueBrush);
            qDebug() << "ellipse1 "<<  ellipse1;
        }
        else
        {
             qDebug() << "else ellipse1 "<<  ellipse1;
             ellipse1->setRect(QRectF(0, 0, 15, 15));
             ellipse1->setPos(mx-40, my-35);
        }
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        if(chkEllipse[2] == 0)
        {
            chkEllipse[2] = 1;
            QBrush greenBrush(Qt::green);
            QPen blackPen(Qt::black);
            ellipse2 = scene.addEllipse(mx-40, my-35, 15, 15, blackPen, greenBrush);
        }
        else
        {
            ellipse2->setRect(QRectF(0, 0, 15, 15));
            ellipse2->setPos(mx-40, my-35);
        }
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
        msgBox.exec();
    }
    msgboxchk = 0;
}

void bluetoothSetting::on_pushButton_2_clicked()
{
    VirtualKeyboard dlg;
 //   dlg.setGeometry(300, 300, 400, 400);
    qDebug()<<"bluetoothsetting: " << ValueCharString;
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiZero_X_value = value;
        printf("%f\n", value);
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseO_X_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseX_X_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
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
        PiZero_Q_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
         PiOneCaseO_Q_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseX_Q_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
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
        PiZero_P_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseO_P_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseX_P_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
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
    if(ui->PiZeroW->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiZero_R_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();

    }
    else if(ui->PiOneCaseO->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseO_R_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        dlg.exec();
        dlg.GetString(ValueCharString);
        double value = atof(ValueCharString);
        PiOneCaseX_R_value = value;
        QMessageBox msgBox;
        msgBox.setText("The value has successfully changed.");
        msgBox.exec();
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
