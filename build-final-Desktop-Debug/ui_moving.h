/********************************************************************************
** Form generated from reading UI file 'moving.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVING_H
#define UI_MOVING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_MOVING
{
public:
    QGraphicsView *graphicsView;
    QSlider *horizontalSlider;

    void setupUi(QDialog *MOVING)
    {
        if (MOVING->objectName().isEmpty())
            MOVING->setObjectName(QStringLiteral("MOVING"));
        MOVING->resize(1000, 600);
        graphicsView = new QGraphicsView(MOVING);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 20, 971, 541));
        horizontalSlider = new QSlider(MOVING);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(809, 485, 171, 71));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(MOVING);

        QMetaObject::connectSlotsByName(MOVING);
    } // setupUi

    void retranslateUi(QDialog *MOVING)
    {
        MOVING->setWindowTitle(QApplication::translate("MOVING", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MOVING: public Ui_MOVING {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVING_H
