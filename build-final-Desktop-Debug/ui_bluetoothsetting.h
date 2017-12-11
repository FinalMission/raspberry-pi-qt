/********************************************************************************
** Form generated from reading UI file 'bluetoothsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLUETOOTHSETTING_H
#define UI_BLUETOOTHSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bluetoothSetting
{
public:
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QRadioButton *PiOneCaseX;
    QRadioButton *PiZeroW;
    QRadioButton *PiOneCaseO;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *Y_Label;
    QLabel *T_Label;
    QLabel *one_p;
    QLabel *two_d;
    QLabel *zero_t;
    QLabel *label_16;
    QLabel *zero_x;
    QLabel *one_r;
    QLabel *label_14;
    QLabel *zero_y;
    QLabel *zero_r;
    QLabel *zero_p;
    QLabel *one_t;
    QLabel *one_x;
    QLabel *Q_Label;
    QLabel *zero_q;
    QLabel *label_15;
    QLabel *two_p;
    QLabel *R_Label;
    QLabel *two_r;
    QLabel *D_Label;
    QLabel *two_x;
    QLabel *Device_Label;
    QLabel *zero_d;
    QLabel *two_t;
    QLabel *two_q;
    QLabel *one_q;
    QLabel *one_y;
    QLabel *two_y;
    QLabel *one_d;
    QLabel *P_Label;
    QLabel *X_Label;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;

    void setupUi(QDialog *bluetoothSetting)
    {
        if (bluetoothSetting->objectName().isEmpty())
            bluetoothSetting->setObjectName(QStringLiteral("bluetoothSetting"));
        bluetoothSetting->resize(781, 505);
        graphicsView = new QGraphicsView(bluetoothSetting);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 1, 750, 351));
        verticalLayoutWidget = new QWidget(bluetoothSetting);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(6, 360, 91, 122));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        PiOneCaseX = new QRadioButton(groupBox);
        PiOneCaseX->setObjectName(QStringLiteral("PiOneCaseX"));
        PiOneCaseX->setGeometry(QRect(0, 70, 89, 27));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(PiOneCaseX->sizePolicy().hasHeightForWidth());
        PiOneCaseX->setSizePolicy(sizePolicy);
        PiZeroW = new QRadioButton(groupBox);
        PiZeroW->setObjectName(QStringLiteral("PiZeroW"));
        PiZeroW->setGeometry(QRect(0, 24, 89, 27));
        sizePolicy.setHeightForWidth(PiZeroW->sizePolicy().hasHeightForWidth());
        PiZeroW->setSizePolicy(sizePolicy);
        PiOneCaseO = new QRadioButton(groupBox);
        PiOneCaseO->setObjectName(QStringLiteral("PiOneCaseO"));
        PiOneCaseO->setGeometry(QRect(0, 47, 89, 27));
        sizePolicy.setHeightForWidth(PiOneCaseO->sizePolicy().hasHeightForWidth());
        PiOneCaseO->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(groupBox);

        gridLayoutWidget_2 = new QWidget(bluetoothSetting);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(226, 360, 531, 121));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        Y_Label = new QLabel(gridLayoutWidget_2);
        Y_Label->setObjectName(QStringLiteral("Y_Label"));
        Y_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(Y_Label, 0, 2, 1, 1);

        T_Label = new QLabel(gridLayoutWidget_2);
        T_Label->setObjectName(QStringLiteral("T_Label"));
        T_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(T_Label, 0, 4, 1, 1);

        one_p = new QLabel(gridLayoutWidget_2);
        one_p->setObjectName(QStringLiteral("one_p"));

        gridLayout_3->addWidget(one_p, 2, 5, 1, 1);

        two_d = new QLabel(gridLayoutWidget_2);
        two_d->setObjectName(QStringLiteral("two_d"));

        gridLayout_3->addWidget(two_d, 3, 3, 1, 1);

        zero_t = new QLabel(gridLayoutWidget_2);
        zero_t->setObjectName(QStringLiteral("zero_t"));

        gridLayout_3->addWidget(zero_t, 1, 4, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(label_16, 3, 0, 1, 1);

        zero_x = new QLabel(gridLayoutWidget_2);
        zero_x->setObjectName(QStringLiteral("zero_x"));

        gridLayout_3->addWidget(zero_x, 1, 1, 1, 1);

        one_r = new QLabel(gridLayoutWidget_2);
        one_r->setObjectName(QStringLiteral("one_r"));

        gridLayout_3->addWidget(one_r, 2, 7, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        zero_y = new QLabel(gridLayoutWidget_2);
        zero_y->setObjectName(QStringLiteral("zero_y"));

        gridLayout_3->addWidget(zero_y, 1, 2, 1, 1);

        zero_r = new QLabel(gridLayoutWidget_2);
        zero_r->setObjectName(QStringLiteral("zero_r"));

        gridLayout_3->addWidget(zero_r, 1, 7, 1, 1);

        zero_p = new QLabel(gridLayoutWidget_2);
        zero_p->setObjectName(QStringLiteral("zero_p"));

        gridLayout_3->addWidget(zero_p, 1, 5, 1, 1);

        one_t = new QLabel(gridLayoutWidget_2);
        one_t->setObjectName(QStringLiteral("one_t"));

        gridLayout_3->addWidget(one_t, 2, 4, 1, 1);

        one_x = new QLabel(gridLayoutWidget_2);
        one_x->setObjectName(QStringLiteral("one_x"));

        gridLayout_3->addWidget(one_x, 2, 1, 1, 1);

        Q_Label = new QLabel(gridLayoutWidget_2);
        Q_Label->setObjectName(QStringLiteral("Q_Label"));
        Q_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(Q_Label, 0, 6, 1, 1);

        zero_q = new QLabel(gridLayoutWidget_2);
        zero_q->setObjectName(QStringLiteral("zero_q"));

        gridLayout_3->addWidget(zero_q, 1, 6, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(label_15, 2, 0, 1, 1);

        two_p = new QLabel(gridLayoutWidget_2);
        two_p->setObjectName(QStringLiteral("two_p"));

        gridLayout_3->addWidget(two_p, 3, 5, 1, 1);

        R_Label = new QLabel(gridLayoutWidget_2);
        R_Label->setObjectName(QStringLiteral("R_Label"));
        R_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(R_Label, 0, 7, 1, 1);

        two_r = new QLabel(gridLayoutWidget_2);
        two_r->setObjectName(QStringLiteral("two_r"));

        gridLayout_3->addWidget(two_r, 3, 7, 1, 1);

        D_Label = new QLabel(gridLayoutWidget_2);
        D_Label->setObjectName(QStringLiteral("D_Label"));
        D_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(D_Label, 0, 3, 1, 1);

        two_x = new QLabel(gridLayoutWidget_2);
        two_x->setObjectName(QStringLiteral("two_x"));

        gridLayout_3->addWidget(two_x, 3, 1, 1, 1);

        Device_Label = new QLabel(gridLayoutWidget_2);
        Device_Label->setObjectName(QStringLiteral("Device_Label"));
        Device_Label->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(Device_Label, 0, 0, 1, 1);

        zero_d = new QLabel(gridLayoutWidget_2);
        zero_d->setObjectName(QStringLiteral("zero_d"));

        gridLayout_3->addWidget(zero_d, 1, 3, 1, 1);

        two_t = new QLabel(gridLayoutWidget_2);
        two_t->setObjectName(QStringLiteral("two_t"));

        gridLayout_3->addWidget(two_t, 3, 4, 1, 1);

        two_q = new QLabel(gridLayoutWidget_2);
        two_q->setObjectName(QStringLiteral("two_q"));

        gridLayout_3->addWidget(two_q, 3, 6, 1, 1);

        one_q = new QLabel(gridLayoutWidget_2);
        one_q->setObjectName(QStringLiteral("one_q"));

        gridLayout_3->addWidget(one_q, 2, 6, 1, 1);

        one_y = new QLabel(gridLayoutWidget_2);
        one_y->setObjectName(QStringLiteral("one_y"));

        gridLayout_3->addWidget(one_y, 2, 2, 1, 1);

        two_y = new QLabel(gridLayoutWidget_2);
        two_y->setObjectName(QStringLiteral("two_y"));

        gridLayout_3->addWidget(two_y, 3, 2, 1, 1);

        one_d = new QLabel(gridLayoutWidget_2);
        one_d->setObjectName(QStringLiteral("one_d"));

        gridLayout_3->addWidget(one_d, 2, 3, 1, 1);

        P_Label = new QLabel(gridLayoutWidget_2);
        P_Label->setObjectName(QStringLiteral("P_Label"));
        P_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(P_Label, 0, 5, 1, 1);

        X_Label = new QLabel(gridLayoutWidget_2);
        X_Label->setObjectName(QStringLiteral("X_Label"));
        X_Label->setMaximumSize(QSize(70, 16777215));

        gridLayout_3->addWidget(X_Label, 0, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(bluetoothSetting);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(104, 360, 111, 121));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pushButton_5, 2, 0, 1, 1);


        retranslateUi(bluetoothSetting);

        QMetaObject::connectSlotsByName(bluetoothSetting);
    } // setupUi

    void retranslateUi(QDialog *bluetoothSetting)
    {
        bluetoothSetting->setWindowTitle(QApplication::translate("bluetoothSetting", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("bluetoothSetting", "Selector", Q_NULLPTR));
        PiOneCaseX->setText(QApplication::translate("bluetoothSetting", "BLE 2", Q_NULLPTR));
        PiZeroW->setText(QApplication::translate("bluetoothSetting", "BLE 0", Q_NULLPTR));
        PiOneCaseO->setText(QApplication::translate("bluetoothSetting", "BLE 1", Q_NULLPTR));
        Y_Label->setText(QApplication::translate("bluetoothSetting", "Y", Q_NULLPTR));
        T_Label->setText(QApplication::translate("bluetoothSetting", "T", Q_NULLPTR));
        one_p->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        two_d->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        zero_t->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        label_16->setText(QApplication::translate("bluetoothSetting", "BLE 2", Q_NULLPTR));
        zero_x->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_r->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        label_14->setText(QApplication::translate("bluetoothSetting", "BLE 0", Q_NULLPTR));
        zero_y->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        zero_r->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        zero_p->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_t->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_x->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        Q_Label->setText(QApplication::translate("bluetoothSetting", "Q", Q_NULLPTR));
        zero_q->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        label_15->setText(QApplication::translate("bluetoothSetting", "BLE 1", Q_NULLPTR));
        two_p->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        R_Label->setText(QApplication::translate("bluetoothSetting", "R", Q_NULLPTR));
        two_r->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        D_Label->setText(QApplication::translate("bluetoothSetting", "D", Q_NULLPTR));
        two_x->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        Device_Label->setText(QApplication::translate("bluetoothSetting", "Device", Q_NULLPTR));
        zero_d->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        two_t->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        two_q->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_q->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_y->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        two_y->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        one_d->setText(QApplication::translate("bluetoothSetting", "NULL", Q_NULLPTR));
        P_Label->setText(QApplication::translate("bluetoothSetting", "P", Q_NULLPTR));
        X_Label->setText(QApplication::translate("bluetoothSetting", "X", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("bluetoothSetting", "Dist", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("bluetoothSetting", "R", Q_NULLPTR));
        pushButton->setText(QApplication::translate("bluetoothSetting", "Q", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("bluetoothSetting", "Tx", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("bluetoothSetting", "P", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("bluetoothSetting", "Appy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class bluetoothSetting: public Ui_bluetoothSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHSETTING_H
