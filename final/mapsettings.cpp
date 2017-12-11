#include "mapsettings.h"
#include "ui_mapsettings.h"
#include "moving.h"
#include "ui_moving.h"
#include <QGraphicsScene>
#include <QFileDialog>
#include "virtualkeyboard.h"
#include <QMessageBox>
#include "mainmenu.h"
#include <string.h>
extern QString selectedMapPath;
char ValueCharString[256];
extern double cm_per_pixel;

mapsettings::mapsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapsettings)
{
    ui->setupUi(this);
    if(selectedMapPath == ":/img/17thfloor.png")
    {
        int index = ui->comboBox->findText("17");
        if ( index != -1 ) { // -1 for not found
            ui->comboBox->setCurrentIndex(index);
        }
    }
    ui->CurrentRatio->setText(QString::number(cm_per_pixel));
    ui->groupBox->setStyleSheet("font-weight: bold;");
}

mapsettings::~mapsettings()
{
//    qDebug()<<"mapsetting: " << ValueCharString;
    //memset(ValueCharString, NULL, sizeof(ValueCharString));
//    qDebug()<<"mapsetting: " << ValueCharString;
    delete ui;
}

void mapsettings::on_comboBox_currentTextChanged(const QString &arg1)
{
     if(ui->comboBox->currentText() == "9")
     {
         selectedMapPath = ":/img/9thfloor.png";
     }
     else if(ui->comboBox->currentText() == "17")
     {
         selectedMapPath = ":/img/17thfloor.png";
     }
}

void mapsettings::on_ApplyButton_clicked()
{
    close();
}

void mapsettings::on_SettingButton_clicked()
{
    VirtualKeyboard dlg;
    memset(ValueCharString, NULL, sizeof(ValueCharString));
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = atof(ValueCharString);
    if(value != 0) cm_per_pixel = value;
    qDebug() << "atof: " << value;
    qDebug() << "ValueCharString: " << ValueCharString;
    ui->CurrentRatio->setText(QString::number(cm_per_pixel));
    QMessageBox msgBox;
    msgBox.setText("The value has successfully changed.");
    msgBox.exec();
}
