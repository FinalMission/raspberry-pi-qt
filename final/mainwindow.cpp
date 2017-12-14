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
   //     printf("error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }

    QPixmap pix(":/img/flashscreen.png");
    scene.addPixmap(pix);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    ui->setupUi(this);

    flashScreen();
}

void MainWindow::flashScreen(void)
{
     sleep(3);
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
        printf("error: %s (%d)\n", strerror(errno), __LINE__);
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
