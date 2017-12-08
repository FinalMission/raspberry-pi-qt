#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moving.h"
#include "ui_moving.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MOVING dlg;
    dlg.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "MOVING GUI PROTOTYPE"));
    dlg.exec();
}
