/********************************************************************************
** Form generated from reading UI file 'playlistwind.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTWIND_H
#define UI_PLAYLISTWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playlistwind
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *playlistwind)
    {
        if (playlistwind->objectName().isEmpty())
            playlistwind->setObjectName(QString::fromUtf8("playlistwind"));
        playlistwind->resize(200, 740);
        listWidget = new QListWidget(playlistwind);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 0, 231, 600));

        retranslateUi(playlistwind);

        QMetaObject::connectSlotsByName(playlistwind);
    } // setupUi

    void retranslateUi(QWidget *playlistwind)
    {
        playlistwind->setWindowTitle(QCoreApplication::translate("playlistwind", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playlistwind: public Ui_playlistwind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTWIND_H
