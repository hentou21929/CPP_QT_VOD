/********************************************************************************
** Form generated from reading UI file 'show.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_H
#define UI_SHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Show
{
public:
    QLabel *label;

    void setupUi(QWidget *Show)
    {
        if (Show->objectName().isEmpty())
            Show->setObjectName(QString::fromUtf8("Show"));
        Show->resize(531, 394);
        label = new QLabel(Show);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 361, 221));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Show);

        QMetaObject::connectSlotsByName(Show);
    } // setupUi

    void retranslateUi(QWidget *Show)
    {
        Show->setWindowTitle(QCoreApplication::translate("Show", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Show: public Ui_Show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_H
