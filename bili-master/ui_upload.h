/********************************************************************************
** Form generated from reading UI file 'upload.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOAD_H
#define UI_UPLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_upload
{
public:
    QPushButton *uploadimg;
    QPushButton *uploadvideo;
    QPushButton *upload_2;
    QLabel *img;
    QLineEdit *videotitle;
    QLineEdit *videopath;
    QWidget *widget;
    QPushButton *pushButton;
    QLabel *progressLabel;

    void setupUi(QWidget *upload)
    {
        if (upload->objectName().isEmpty())
            upload->setObjectName(QString::fromUtf8("upload"));
        upload->resize(720, 540);
        upload->setMinimumSize(QSize(720, 540));
        upload->setMaximumSize(QSize(720, 540));
        upload->setStyleSheet(QString::fromUtf8("background-color: rgb(63, 63, 63);"));
        uploadimg = new QPushButton(upload);
        uploadimg->setObjectName(QString::fromUtf8("uploadimg"));
        uploadimg->setGeometry(QRect(70, 400, 161, 61));
        uploadimg->setCursor(QCursor(Qt::PointingHandCursor));
        uploadimg->setStyleSheet(QString::fromUtf8("background-color: rgb(251,114,153);\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"border-radius: 5px\n"
""));
        uploadvideo = new QPushButton(upload);
        uploadvideo->setObjectName(QString::fromUtf8("uploadvideo"));
        uploadvideo->setGeometry(QRect(450, 390, 161, 61));
        uploadvideo->setCursor(QCursor(Qt::PointingHandCursor));
        uploadvideo->setStyleSheet(QString::fromUtf8("background-color: rgb(251,114,153);\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"border-radius: 5px\n"
""));
        upload_2 = new QPushButton(upload);
        upload_2->setObjectName(QString::fromUtf8("upload_2"));
        upload_2->setGeometry(QRect(260, 470, 161, 61));
        upload_2->setCursor(QCursor(Qt::PointingHandCursor));
        upload_2->setStyleSheet(QString::fromUtf8("background-color: rgb(251,114,153);\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"border-radius: 5px\n"
""));
        img = new QLabel(upload);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(190, 40, 321, 181));
        img->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        videotitle = new QLineEdit(upload);
        videotitle->setObjectName(QString::fromUtf8("videotitle"));
        videotitle->setGeometry(QRect(182, 252, 341, 31));
        videotitle->setStyleSheet(QString::fromUtf8("color: rgba(147, 147, 147);\n"
"background-color: rgb(255, 255, 255);"));
        videopath = new QLineEdit(upload);
        videopath->setObjectName(QString::fromUtf8("videopath"));
        videopath->setGeometry(QRect(180, 320, 341, 31));
        videopath->setCursor(QCursor(Qt::ForbiddenCursor));
        videopath->setStyleSheet(QString::fromUtf8("color: rgba(147, 147, 147, 50);\n"
"background-color: rgb(255, 255, 255);"));
        widget = new QWidget(upload);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(-20, 0, 750, 31));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(710, 0, 31, 31));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/res/images/close2.png);\n"
"border-image: url(:/res/images/close2.png);"));
        progressLabel = new QLabel(upload);
        progressLabel->setObjectName(QString::fromUtf8("progressLabel"));
        progressLabel->setGeometry(QRect(280, 100, 141, 41));
        progressLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(251,114,153);\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"border-radius: 5px"));

        retranslateUi(upload);

        QMetaObject::connectSlotsByName(upload);
    } // setupUi

    void retranslateUi(QWidget *upload)
    {
        upload->setWindowTitle(QCoreApplication::translate("upload", "Form", nullptr));
        uploadimg->setText(QCoreApplication::translate("upload", "\351\200\211\346\213\251\345\260\201\351\235\242", nullptr));
        uploadvideo->setText(QCoreApplication::translate("upload", "\351\200\211\346\213\251\350\247\206\351\242\221", nullptr));
        upload_2->setText(QCoreApplication::translate("upload", "\344\270\212\344\274\240", nullptr));
        img->setText(QCoreApplication::translate("upload", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; color:#ffffff; vertical-align:super;\">\350\247\206\351\242\221\345\260\201\351\235\242</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        videotitle->setToolTip(QCoreApplication::translate("upload", "<html><head/><body><p><span style=\" color:#000000;\">\350\247\206\351\242\221\346\240\207\351\242\230</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        videotitle->setWhatsThis(QCoreApplication::translate("upload", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700; color:#ffffff;\">\350\276\223\345\205\245\350\247\206\351\242\221\346\240\207\351\242\230\357\274\232</span></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        videotitle->setText(QCoreApplication::translate("upload", "\350\247\206\351\242\221\346\240\207\351\242\230", nullptr));
#if QT_CONFIG(tooltip)
        videopath->setToolTip(QCoreApplication::translate("upload", "<html><head/><body><p>\350\247\206\351\242\221\345\234\260\345\235\200</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
        progressLabel->setText(QCoreApplication::translate("upload", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class upload: public Ui_upload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOAD_H
