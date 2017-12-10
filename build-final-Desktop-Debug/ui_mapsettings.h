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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mapsettings
{
public:
    QPushButton *ApplyButton;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *CurrentRatio;
    QComboBox *comboBox;
    QLabel *label_2;
    QPushButton *SettingButton;

    void setupUi(QDialog *mapsettings)
    {
        if (mapsettings->objectName().isEmpty())
            mapsettings->setObjectName(QStringLiteral("mapsettings"));
        mapsettings->resize(362, 202);
        ApplyButton = new QPushButton(mapsettings);
        ApplyButton->setObjectName(QStringLiteral("ApplyButton"));
        ApplyButton->setGeometry(QRect(250, 170, 91, 29));
        groupBox = new QGroupBox(mapsettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 331, 151));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 311, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        CurrentRatio = new QLabel(gridLayoutWidget);
        CurrentRatio->setObjectName(QStringLiteral("CurrentRatio"));

        gridLayout->addWidget(CurrentRatio, 0, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        SettingButton = new QPushButton(gridLayoutWidget);
        SettingButton->setObjectName(QStringLiteral("SettingButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(15);
        sizePolicy.setVerticalStretch(15);
        sizePolicy.setHeightForWidth(SettingButton->sizePolicy().hasHeightForWidth());
        SettingButton->setSizePolicy(sizePolicy);
        SettingButton->setMinimumSize(QSize(0, 0));
        SettingButton->setMaximumSize(QSize(55, 50));
        SettingButton->setStyleSheet(QLatin1String("#SettingButton\n"
"{\n"
"	background-image: url(:/img/settingIcon.png);\n"
"}"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("setting");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        SettingButton->setIcon(icon);

        gridLayout->addWidget(SettingButton, 0, 2, 1, 1);


        retranslateUi(mapsettings);

        QMetaObject::connectSlotsByName(mapsettings);
    } // setupUi

    void retranslateUi(QDialog *mapsettings)
    {
        mapsettings->setWindowTitle(QApplication::translate("mapsettings", "Dialog", Q_NULLPTR));
        ApplyButton->setText(QApplication::translate("mapsettings", "Apply", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("mapsettings", "Setting", Q_NULLPTR));
        label_3->setText(QApplication::translate("mapsettings", "Selected Floor:", Q_NULLPTR));
        CurrentRatio->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mapsettings", "9", Q_NULLPTR)
         << QApplication::translate("mapsettings", "17", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("mapsettings", "Current Ratio:", Q_NULLPTR));
        SettingButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mapsettings: public Ui_mapsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPSETTINGS_H
