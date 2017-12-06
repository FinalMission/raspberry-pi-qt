#include "moving.h"
#include "ui_moving.h"

MOVING::MOVING(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MOVING)
{
    ui->setupUi(this);

    QPixmap pix("17thfloor.png");
    scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    ellipse = scene.addEllipse(180, 100, 30, 30, blackPen, redBrush);
    ellipse->setPos(200,100);

}

MOVING::~MOVING()
{
    delete ui;
}

