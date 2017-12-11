#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QDialog>

namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public QDialog
{
    Q_OBJECT
    
public:
    explicit VirtualKeyboard(QWidget *parent = 0);
    ~VirtualKeyboard();
    void GetString(char *);
    
private slots:
    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Dot_clicked();

    void on_Zero_clicked();

    void on_Backspace_clicked();

    void on_DoneButton_clicked();

    void on_Minus_clicked();

private:
    Ui::VirtualKeyboard *ui;
};

#endif // VIRTUALKEYBOARD_H
