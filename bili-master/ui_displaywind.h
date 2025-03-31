/********************************************************************************
** Form generated from reading UI file 'displaywind.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWIND_H
#define UI_DISPLAYWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaywind
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *displaywind)
    {
        if (displaywind->objectName().isEmpty())
            displaywind->setObjectName(QString::fromUtf8("displaywind"));
        displaywind->resize(1080, 580);
        displaywind->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(0, 0, 0)"));
        pushButton = new QPushButton(displaywind);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 210, 161, 61));

        retranslateUi(displaywind);

        QMetaObject::connectSlotsByName(displaywind);
    } // setupUi

    void retranslateUi(QWidget *displaywind)
    {
        displaywind->setWindowTitle(QCoreApplication::translate("displaywind", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("displaywind", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaywind: public Ui_displaywind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWIND_H
