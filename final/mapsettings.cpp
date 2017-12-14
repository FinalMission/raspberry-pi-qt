#include "mapsettings.h"
#include "ui_mapsettings.h"
#include "moving.h"
#include "ui_moving.h"
#include <QGraphicsScene>
mapsettings::mapsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapsettings)
{
    ui->setupUi(this);
}

mapsettings::~mapsettings()
{
    delete ui;
}

void mapsettings::on_pushButton_2_clicked()
{
    MOVING dlg;

//    QString fileName = QFileDialog::getOpenFileName(this,tr("ChangeFloor"),":/img",tr("images(*.bmp)"));
    //dlg.ui->graphicsView->setPixmap(QPixmap(fileName));
//    QPixmap pix(fileName);
 //   dlg.scene.addPixmap(pix);
  //  dlg.ui->graphicsView->setScene(&scene);
//    dlg.ui->graphicsView->show();
 //   dlg.exec();
}
