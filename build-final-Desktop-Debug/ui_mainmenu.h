/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *mapButton;
    QPushButton *BLEButton;
    QPushButton *mapsetButton;
    QPushButton *pushButton;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 480);
        mapButton = new QPushButton(MainMenu);
        mapButton->setObjectName(QStringLiteral("mapButton"));
        mapButton->setGeometry(QRect(270, 110, 271, 251));
        mapButton->setStyleSheet(QLatin1String("#mapButton\n"
"{\n"
"	background-image: url(:/img/mapIcon.png);\n"
"}"));
        BLEButton = new QPushButton(MainMenu);
        BLEButton->setObjectName(QStringLiteral("BLEButton"));
        BLEButton->setGeometry(QRect(-4, 0, 271, 481));
        mapsetButton = new QPushButton(MainMenu);
        mapsetButton->setObjectName(QStringLiteral("mapsetButton"));
        mapsetButton->setGeometry(QRect(535, 0, 266, 481));
        pushButton = new QPushButton(MainMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(770, 0, 31, 31));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Dialog", Q_NULLPTR));
        mapButton->setText(QApplication::translate("MainMenu", "map", Q_NULLPTR));
        BLEButton->setText(QApplication::translate("MainMenu", "bluetooth setting", Q_NULLPTR));
        mapsetButton->setText(QApplication::translate("MainMenu", "mapsetting", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainMenu", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
