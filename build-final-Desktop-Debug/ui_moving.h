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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_MOVING
{
public:
    QGraphicsView *graphicsView;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *MOVING)
    {
        if (MOVING->objectName().isEmpty())
            MOVING->setObjectName(QStringLiteral("MOVING"));
        MOVING->resize(840, 658);
        graphicsView = new QGraphicsView(MOVING);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 480));
        horizontalSlider = new QSlider(MOVING);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(624, 404, 171, 71));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(MOVING);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(769, 0, 30, 30));
        pushButton_2 = new QPushButton(MOVING);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 430, 91, 29));
        checkBox = new QCheckBox(MOVING);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 430, 101, 27));
        graphicsView->raise();
        pushButton->raise();
        horizontalSlider->raise();
        pushButton_2->raise();
        checkBox->raise();

        retranslateUi(MOVING);

        QMetaObject::connectSlotsByName(MOVING);
    } // setupUi

    void retranslateUi(QDialog *MOVING)
    {
        MOVING->setWindowTitle(QApplication::translate("MOVING", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MOVING", "X", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MOVING", "Navi Start", Q_NULLPTR));
        checkBox->setText(QApplication::translate("MOVING", "Navi Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MOVING: public Ui_MOVING {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVING_H
