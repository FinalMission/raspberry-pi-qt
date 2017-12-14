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
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_mapButton_clicked()
{
    MOVING dlg;
    dlg.exec();
}

void MainMenu::on_mapsetButton_clicked()
{
    mapsettings dlg;
    dlg.exec();
}

void MainMenu::on_BLEButton_clicked()
{
    bluetoothSetting dlg;
    dlg.exec();
}
