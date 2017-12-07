/********************************************************************************
** Form generated from reading UI file 'moving.ui'
**
** Created: Wed Dec 6 09:42:28 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVING_H
#define UI_MOVING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MOVING
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QDialog *MOVING)
    {
        if (MOVING->objectName().isEmpty())
            MOVING->setObjectName(QString::fromUtf8("MOVING"));
        MOVING->resize(1000, 600);
        graphicsView = new QGraphicsView(MOVING);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 971, 541));

        retranslateUi(MOVING);

        QMetaObject::connectSlotsByName(MOVING);
    } // setupUi

    void retranslateUi(QDialog *MOVING)
    {
        MOVING->setWindowTitle(QApplication::translate("MOVING", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MOVING: public Ui_MOVING {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVING_H
