#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    
private slots:
    void on_mapButton_clicked();

    void on_mapsetButton_clicked();

    void on_BLEButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
