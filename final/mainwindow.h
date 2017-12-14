#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    //void on_pushButton_clicked();
    void flashScreen();
private:
    Ui::MainWindow *ui;
    QGraphicsScene scene1;
    int id_shm;
    int ret;
};

#endif // MAINWINDOW_H
