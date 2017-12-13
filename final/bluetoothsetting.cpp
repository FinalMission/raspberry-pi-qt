#include "bluetoothsetting.h"
#include "ui_bluetoothsetting.h"
#include <QTouchEvent>
#include "virtualkeyboard.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
int chkEllipse[3];
int msgboxchk;

bluetoothSetting::bluetoothSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bluetoothSetting)
{
    Pressed=false;
    QPixmap pix(":/img/9thfloor.png");
    scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();

    ui->setupUi(this);
}

bluetoothSetting::~bluetoothSetting()
{
    delete ui;
}

void bluetoothSetting::mousePressEvent(QMouseEvent *event)
{
    int mx, my;
    mx = event->pos().x();
    my = event->pos().y();
    if(mx <= 0 || mx >= 750 || my <= 0 || my >= 351) return;

    if(ui->PiZeroW->isChecked())
    {
        if(chkEllipse[0])
        {
            ellipse0->setPos(mx, my);
        }
        else
        {
            chkEllipse[0] = 1;
            QBrush redBrush(Qt::red);
            QPen blackPen(Qt::black);
            ellipse0 = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
        }
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        if(chkEllipse[1])
        {
            ellipse1->setPos(mx, my);
        }
        else
        {
            chkEllipse[1] = 1;
            QBrush redBrush(Qt::red);
            QPen blackPen(Qt::black);
            ellipse1 = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
        }
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        if(chkEllipse[2])
        {
            ellipse2->setPos(mx, my);
        }
        else
        {
            chkEllipse[2] = 1;
            QBrush redBrush(Qt::red);
            QPen blackPen(Qt::black);
            ellipse2 = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
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
    QString ValueCharString;
    VirtualKeyboard dlg;
    dlg.setGeometry(300, 300, 400, 400);
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = ValueCharString.toInt();
    if(ui->PiZeroW->isChecked())
    {
        value = PiZero_X_value;
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        value = PiOneCaseO_X_value;
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        value = PiOneCaseX_X_value;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Opps!! You need to select a device. Try again.");
        msgBox.exec();
    }
}

void bluetoothSetting::on_pushButton_clicked()
{
    QString ValueCharString;
    VirtualKeyboard dlg;
    dlg.setGeometry(300, 300, 400, 400);
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = ValueCharString.toInt();
    if(ui->PiZeroW->isChecked())
    {
        value = PiZero_Q_value;
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        value = PiOneCaseO_Q_value;
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        value = PiOneCaseX_Q_value;
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
    QString ValueCharString;
    VirtualKeyboard dlg;
    dlg.setGeometry(300, 300, 400, 400);
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = ValueCharString.toInt();
    if(ui->PiZeroW->isChecked())
    {
        value = PiZero_P_value;
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        value = PiOneCaseO_P_value;
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        value = PiOneCaseX_P_value;
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
    QString ValueCharString;
    VirtualKeyboard dlg;
    dlg.setGeometry(300, 300, 400, 400);
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = ValueCharString.toInt();
    if(ui->PiZeroW->isChecked())
    {
        value = PiZero_R_value;
    }
    else if(ui->PiOneCaseO->isChecked())
    {
        value = PiOneCaseO_R_value;
    }
    else if(ui->PiOneCaseX->isChecked())
    {
        value = PiOneCaseX_R_value;
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
