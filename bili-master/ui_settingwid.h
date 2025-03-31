/********************************************************************************
** Form generated from reading UI file 'settingwid.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWID_H
#define UI_SETTINGWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWid
{
public:

    void setupUi(QWidget *SettingWid)
    {
        if (SettingWid->objectName().isEmpty())
            SettingWid->setObjectName(QString::fromUtf8("SettingWid"));
        SettingWid->resize(400, 300);

        retranslateUi(SettingWid);

        QMetaObject::connectSlotsByName(SettingWid);
    } // setupUi

    void retranslateUi(QWidget *SettingWid)
    {
        SettingWid->setWindowTitle(QCoreApplication::translate("SettingWid", "PlayerDemo \350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWid: public Ui_SettingWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWID_H
