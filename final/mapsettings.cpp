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
}

mapsettings::~mapsettings()
{
    qDebug()<<"mapsetting: " << ValueCharString;
    //memset(ValueCharString, NULL, sizeof(ValueCharString));
    qDebug()<<"mapsetting: " << ValueCharString;
    delete ui;
}

void mapsettings::on_pushButton_clicked()
{
    VirtualKeyboard dlg;
    dlg.exec();
    dlg.GetString(ValueCharString);
    double value = atof(ValueCharString);
    //cmPerPixel = value;
    ui->CurrentRatio->setText(ValueCharString);
    QMessageBox msgBox;
    msgBox.setText("The value has successfully changed.");
    msgBox.exec();
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
