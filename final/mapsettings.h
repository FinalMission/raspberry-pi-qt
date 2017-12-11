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

    
private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

//    void on_comboBox_activated(int index);

    void on_ApplyButton_clicked();

    void on_SettingButton_clicked();

private:
    Ui::mapsettings *ui;

};

#endif // MAPSETTINGS_H
