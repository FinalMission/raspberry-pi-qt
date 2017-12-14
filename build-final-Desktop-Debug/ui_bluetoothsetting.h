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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *PiZeroW;
    QRadioButton *PiOneCaseO;
    QRadioButton *PiOneCaseX;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line_2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *bluetoothSetting)
    {
        if (bluetoothSetting->objectName().isEmpty())
            bluetoothSetting->setObjectName(QStringLiteral("bluetoothSetting"));
        bluetoothSetting->resize(835, 516);
        graphicsView = new QGraphicsView(bluetoothSetting);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 1, 821, 401));
        horizontalLayoutWidget = new QWidget(bluetoothSetting);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(22, 398, 731, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        PiZeroW = new QRadioButton(horizontalLayoutWidget);
        PiZeroW->setObjectName(QStringLiteral("PiZeroW"));

        horizontalLayout->addWidget(PiZeroW);

        PiOneCaseO = new QRadioButton(horizontalLayoutWidget);
        PiOneCaseO->setObjectName(QStringLiteral("PiOneCaseO"));

        horizontalLayout->addWidget(PiOneCaseO);

        PiOneCaseX = new QRadioButton(horizontalLayoutWidget);
        PiOneCaseX->setObjectName(QStringLiteral("PiOneCaseX"));

        horizontalLayout->addWidget(PiOneCaseX);

        verticalLayoutWidget = new QWidget(bluetoothSetting);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(22, 420, 731, 61));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(7);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        pushButton_5 = new QPushButton(bluetoothSetting);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(583, 480, 171, 31));

        retranslateUi(bluetoothSetting);

        QMetaObject::connectSlotsByName(bluetoothSetting);
    } // setupUi

    void retranslateUi(QDialog *bluetoothSetting)
    {
        bluetoothSetting->setWindowTitle(QApplication::translate("bluetoothSetting", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("bluetoothSetting", "Bluetooth Selection:", Q_NULLPTR));
        PiZeroW->setText(QApplication::translate("bluetoothSetting", "Bluetooth1(PiZeroW)", Q_NULLPTR));
        PiOneCaseO->setText(QApplication::translate("bluetoothSetting", "Bluetooth2(PiOneCaseO)", Q_NULLPTR));
        PiOneCaseX->setText(QApplication::translate("bluetoothSetting", "Bluetooth3(PiOneCaseX)", Q_NULLPTR));
        label_2->setText(QApplication::translate("bluetoothSetting", "Device Setting:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("bluetoothSetting", "X value", Q_NULLPTR));
        pushButton->setText(QApplication::translate("bluetoothSetting", "Q value", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("bluetoothSetting", "P value", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("bluetoothSetting", "R value", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("bluetoothSetting", "MAIN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class bluetoothSetting: public Ui_bluetoothSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLUETOOTHSETTING_H
