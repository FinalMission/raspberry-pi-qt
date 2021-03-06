#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "moving.h"
#include "mapsettings.h"
#include "bluetoothsetting.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
/*    QPalette pal = ui->palette();
    pal.setColor(QPalette::Window, Qt::yellow);
    ui->setPalette(pal); */
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_mapButton_clicked()
{
    MOVING dlg;
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.setStyleSheet("QMainWindow {background: 'yellow';}");
    dlg.exec();
}

void MainMenu::on_mapsetButton_clicked()
{
    mapsettings dlg;
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.exec();
}

void MainMenu::on_BLEButton_clicked()
{
    bluetoothSetting dlg;
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.exec();
}

void MainMenu::on_pushButton_clicked()
{
    close();
}
