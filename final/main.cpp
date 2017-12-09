#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QDebug>
#include <sys/types.h>
#include <unistd.h>

pid_t pid_temp;

QString selectedMapPath = ":/img/9thfloor.png";
//QString scannerProgramPath = "/home/pi/workspace/raspberrypi-bluetooth/bin/scan";

int main(int argc, char *argv[])
{
    qDebug() << "..!!";
    pid_temp = fork();
    if (pid_temp == 0) {
        qDebug() << "qDebug!!";
        execlp("sudo", "sudo", "/home/pi/workspace/raspberrypi-bluetooth/bin/scan", NULL);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
