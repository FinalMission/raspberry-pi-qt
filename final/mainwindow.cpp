#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moving.h"
#include "ui_moving.h"
#include "shm.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include "mainmenu.h"

Packet * packetshm;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    id_shm = shmget((key_t)KEY_SHM, sizeof(Packet[3]), 0777);
    if(id_shm == ERROR)
    {
  //      printf("error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }
    packetshm = (Packet *)shmat(id_shm, (void *)0, 0);
    if(packetshm == (Packet *)ERROR)
    {
        printf("attach shared memory error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }

  ui->setupUi(this);


  QPixmap pix(":/img/flashscreen.png");
  scene1.addPixmap(pix);
  ui->graphicsView->setScene(&scene1);
  ui->graphicsView->show();
  this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//  QTimer::singleShot(3000, this, SLOT(flashScreen()));
  flashScreen();
}

void MainWindow::flashScreen(void)
{
    MainMenu dlg;
    //dlg.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "MOVING GUI PROTOTYPE"));
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.exec();
}

MainWindow::~MainWindow()
{
    ret = shmdt(packetshm);
    if(ret == ERROR)
    {
        printf("detach shared memory error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
    MOVING dlg;
    //dlg.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "MOVING GUI PROTOTYPE"));
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.exec();
}*/
