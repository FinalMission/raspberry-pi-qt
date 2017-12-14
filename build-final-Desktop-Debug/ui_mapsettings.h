/********************************************************************************
** Form generated from reading UI file 'mapsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPSETTINGS_H
#define UI_MAPSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mapsettings
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *mapsettings)
    {
        if (mapsettings->objectName().isEmpty())
            mapsettings->setObjectName(QStringLiteral("mapsettings"));
        mapsettings->resize(800, 640);
        pushButton = new QPushButton(mapsettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 150, 151, 31));
        pushButton_2 = new QPushButton(mapsettings);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 200, 151, 31));

        retranslateUi(mapsettings);

        QMetaObject::connectSlotsByName(mapsettings);
    } // setupUi

    void retranslateUi(QDialog *mapsettings)
    {
        mapsettings->setWindowTitle(QApplication::translate("mapsettings", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mapsettings", "Changeratio", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mapsettings", "ChangeFloor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mapsettings: public Ui_mapsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPSETTINGS_H
