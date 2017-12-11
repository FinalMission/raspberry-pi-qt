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
    id_shm = shmget((key_t)KEY_SHM, sizeof(Packet[3]), 0777|IPC_CREAT);
    packetshm = (Packet *)shmat(id_shm, (void *)0, 0);

    /*if(id_shm == ERROR)
    {
        printf("error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }
    */
    /*if(packetshm == (Packet *)ERROR)
    {
        printf("attach shared memory error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }*/

  ui->setupUi(this);


  QPixmap pix(":/img/flashscreen.png");
  scene1.addPixmap(pix);
  ui->graphicsView->setScene(&scene1);
  ui->graphicsView->show();
  this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  QTimer::singleShot(10, this, SLOT(flashScreen()));
}

void MainWindow::flashScreen(void)
{
    MainMenu dlg;
    //dlg.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "MOVING GUI PROTOTYPE"));
    dlg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    dlg.exec();
//    MainWindow::~MainWindow();
    QTimer::singleShot(1, this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    qDebug() <<"des called";
    ret = shmdt(packetshm);
    /*
    if(ret == ERROR)
    {
        printf("detach shared memory error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }
    */
}

