/********************************************************************************
** Form generated from reading UI file 'virtualkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALKEYBOARD_H
#define UI_VIRTUALKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VirtualKeyboard
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Five;
    QPushButton *Nine;
    QPushButton *One;
    QPushButton *Zero;
    QPushButton *Seven;
    QPushButton *Three;
    QPushButton *Six;
    QPushButton *Four;
    QPushButton *Two;
    QPushButton *Eight;
    QPushButton *Dot;
    QPushButton *Backspace;
    QLabel *label;
    QLabel *TypedText;

    void setupUi(QDialog *VirtualKeyboard)
    {
        if (VirtualKeyboard->objectName().isEmpty())
            VirtualKeyboard->setObjectName(QStringLiteral("VirtualKeyboard"));
        VirtualKeyboard->resize(496, 272);
        gridLayoutWidget = new QWidget(VirtualKeyboard);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(170, 10, 311, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Five = new QPushButton(gridLayoutWidget);
        Five->setObjectName(QStringLiteral("Five"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Five->sizePolicy().hasHeightForWidth());
        Five->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Five, 1, 1, 1, 1);

        Nine = new QPushButton(gridLayoutWidget);
        Nine->setObjectName(QStringLiteral("Nine"));
        sizePolicy.setHeightForWidth(Nine->sizePolicy().hasHeightForWidth());
        Nine->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Nine, 2, 2, 1, 1);

        One = new QPushButton(gridLayoutWidget);
        One->setObjectName(QStringLiteral("One"));
        sizePolicy.setHeightForWidth(One->sizePolicy().hasHeightForWidth());
        One->setSizePolicy(sizePolicy);

        gridLayout->addWidget(One, 0, 0, 1, 1);

        Zero = new QPushButton(gridLayoutWidget);
        Zero->setObjectName(QStringLiteral("Zero"));
        sizePolicy.setHeightForWidth(Zero->sizePolicy().hasHeightForWidth());
        Zero->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Zero, 3, 0, 1, 1);

        Seven = new QPushButton(gridLayoutWidget);
        Seven->setObjectName(QStringLiteral("Seven"));
        sizePolicy.setHeightForWidth(Seven->sizePolicy().hasHeightForWidth());
        Seven->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Seven, 2, 0, 1, 1);

        Three = new QPushButton(gridLayoutWidget);
        Three->setObjectName(QStringLiteral("Three"));
        sizePolicy.setHeightForWidth(Three->sizePolicy().hasHeightForWidth());
        Three->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Three, 0, 2, 1, 1);

        Six = new QPushButton(gridLayoutWidget);
        Six->setObjectName(QStringLiteral("Six"));
        sizePolicy.setHeightForWidth(Six->sizePolicy().hasHeightForWidth());
        Six->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Six, 1, 2, 1, 1);

        Four = new QPushButton(gridLayoutWidget);
        Four->setObjectName(QStringLiteral("Four"));
        sizePolicy.setHeightForWidth(Four->sizePolicy().hasHeightForWidth());
        Four->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Four, 1, 0, 1, 1);

        Two = new QPushButton(gridLayoutWidget);
        Two->setObjectName(QStringLiteral("Two"));
        sizePolicy.setHeightForWidth(Two->sizePolicy().hasHeightForWidth());
        Two->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Two, 0, 1, 1, 1);

        Eight = new QPushButton(gridLayoutWidget);
        Eight->setObjectName(QStringLiteral("Eight"));
        sizePolicy.setHeightForWidth(Eight->sizePolicy().hasHeightForWidth());
        Eight->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Eight, 2, 1, 1, 1);

        Dot = new QPushButton(gridLayoutWidget);
        Dot->setObjectName(QStringLiteral("Dot"));
        sizePolicy.setHeightForWidth(Dot->sizePolicy().hasHeightForWidth());
        Dot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(Dot, 3, 1, 1, 1);

        Backspace = new QPushButton(gridLayoutWidget);
        Backspace->setObjectName(QStringLiteral("Backspace"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Backspace->sizePolicy().hasHeightForWidth());
        Backspace->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Backspace, 3, 2, 1, 1);

        label = new QLabel(VirtualKeyboard);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 91, 20));
        TypedText = new QLabel(VirtualKeyboard);
        TypedText->setObjectName(QStringLiteral("TypedText"));
        TypedText->setGeometry(QRect(10, 60, 131, 51));

        retranslateUi(VirtualKeyboard);

        QMetaObject::connectSlotsByName(VirtualKeyboard);
    } // setupUi

    void retranslateUi(QDialog *VirtualKeyboard)
    {
        VirtualKeyboard->setWindowTitle(QApplication::translate("VirtualKeyboard", "Dialog", Q_NULLPTR));
        Five->setText(QApplication::translate("VirtualKeyboard", "5", Q_NULLPTR));
        Nine->setText(QApplication::translate("VirtualKeyboard", "9", Q_NULLPTR));
        One->setText(QApplication::translate("VirtualKeyboard", "1", Q_NULLPTR));
        Zero->setText(QApplication::translate("VirtualKeyboard", "0", Q_NULLPTR));
        Seven->setText(QApplication::translate("VirtualKeyboard", "7", Q_NULLPTR));
        Three->setText(QApplication::translate("VirtualKeyboard", "3", Q_NULLPTR));
        Six->setText(QApplication::translate("VirtualKeyboard", "6", Q_NULLPTR));
        Four->setText(QApplication::translate("VirtualKeyboard", "4", Q_NULLPTR));
        Two->setText(QApplication::translate("VirtualKeyboard", "2", Q_NULLPTR));
        Eight->setText(QApplication::translate("VirtualKeyboard", "8", Q_NULLPTR));
        Dot->setText(QApplication::translate("VirtualKeyboard", ".", Q_NULLPTR));
        Backspace->setText(QApplication::translate("VirtualKeyboard", "Backspace", Q_NULLPTR));
        label->setText(QApplication::translate("VirtualKeyboard", "You Typed in:", Q_NULLPTR));
        TypedText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VirtualKeyboard: public Ui_VirtualKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALKEYBOARD_H
