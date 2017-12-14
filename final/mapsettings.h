#ifndef MAPSETTINGS_H
#define MAPSETTINGS_H

#include <QDialog>

namespace Ui {
class mapsettings;
}

class mapsettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit mapsettings(QWidget *parent = 0);
    ~mapsettings();
 QString fileName;

    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

//    void on_comboBox_activated(int index);

private:
    Ui::mapsettings *ui;
    char ValueCharString[256];
};

#endif // MAPSETTINGS_H
