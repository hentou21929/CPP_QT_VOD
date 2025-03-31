/********************************************************************************
** Form generated from reading UI file 'vedioplayer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEDIOPLAYER_H
#define UI_VEDIOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QWidget>
#include <ctrlbar.h>
#include <displaywind.h>
#include <playlistwind.h>

QT_BEGIN_NAMESPACE

class Ui_vedioplayer
{
public:
    QDockWidget *playlistdock;
    playlistwind *playlistcontents_2;
    ctrlbar *ctrlbarwind;
    displaywind *showwind;

    void setupUi(QWidget *vedioplayer)
    {
        if (vedioplayer->objectName().isEmpty())
            vedioplayer->setObjectName(QString::fromUtf8("vedioplayer"));
        vedioplayer->resize(1200, 720);
        vedioplayer->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 50, 52);"));
        playlistdock = new QDockWidget(vedioplayer);
        playlistdock->setObjectName(QString::fromUtf8("playlistdock"));
        playlistdock->setGeometry(QRect(950, 0, 231, 600));
        playlistcontents_2 = new playlistwind();
        playlistcontents_2->setObjectName(QString::fromUtf8("playlistcontents_2"));
        playlistcontents_2->setStyleSheet(QString::fromUtf8("background-color: rgb(98, 98, 98);"));
        playlistdock->setWidget(playlistcontents_2);
        ctrlbarwind = new ctrlbar(vedioplayer);
        ctrlbarwind->setObjectName(QString::fromUtf8("ctrlbarwind"));
        ctrlbarwind->setGeometry(QRect(0, 640, 1000, 70));
        ctrlbarwind->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 255, 208);"));
        showwind = new displaywind(vedioplayer);
        showwind->setObjectName(QString::fromUtf8("showwind"));
        showwind->setGeometry(QRect(0, 60, 1080, 580));
        showwind->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        retranslateUi(vedioplayer);

        QMetaObject::connectSlotsByName(vedioplayer);
    } // setupUi

    void retranslateUi(QWidget *vedioplayer)
    {
        vedioplayer->setWindowTitle(QCoreApplication::translate("vedioplayer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vedioplayer: public Ui_vedioplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEDIOPLAYER_H
