#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moving.h"
#include "ui_moving.h"
#include "shm.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
Packet * packetshm;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    id_shm = shmget((key_t)KEY_SHM, sizeof(Packet[3]), 0777);
    if(id_shm == ERROR)
    {
        printf("error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }
    packetshm = (Packet *)shmat(id_shm, (void *)0, 0);
    if(packetshm == (Packet *)ERROR)
    {
        printf("error: %s (%d)\n", strerror(errno), __LINE__);
        //return EXIT_FAILURE;
    }

    ui->setupUi(this);
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

void MainWindow::on_pushButton_clicked()
{
    MOVING dlg;
    dlg.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "MOVING GUI PROTOTYPE"));
    dlg.exec();
}
