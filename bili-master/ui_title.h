/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Title
{
public:
    QGridLayout *gridLayout;
    QPushButton *MenuBtn;
    QPushButton *MinBtn;
    QLabel *MovieNameLab;
    QPushButton *CloseBtn;
    QPushButton *MaxBtn;
    QPushButton *FullScreenBtn;

    void setupUi(QWidget *Title)
    {
        if (Title->objectName().isEmpty())
            Title->setObjectName(QString::fromUtf8("Title"));
        Title->resize(826, 50);
        Title->setMaximumSize(QSize(16777215, 50));
        gridLayout = new QGridLayout(Title);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        MenuBtn = new QPushButton(Title);
        MenuBtn->setObjectName(QString::fromUtf8("MenuBtn"));
        MenuBtn->setMinimumSize(QSize(130, 0));
        MenuBtn->setMaximumSize(QSize(200, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light SemiCondensed")});
        font.setPointSize(18);
        MenuBtn->setFont(font);

        gridLayout->addWidget(MenuBtn, 0, 0, 1, 1);

        MinBtn = new QPushButton(Title);
        MinBtn->setObjectName(QString::fromUtf8("MinBtn"));
        MinBtn->setMinimumSize(QSize(50, 50));
        MinBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(MinBtn, 0, 2, 1, 1);

        MovieNameLab = new QLabel(Title);
        MovieNameLab->setObjectName(QString::fromUtf8("MovieNameLab"));
        MovieNameLab->setMargin(15);

        gridLayout->addWidget(MovieNameLab, 0, 1, 1, 1);

        CloseBtn = new QPushButton(Title);
        CloseBtn->setObjectName(QString::fromUtf8("CloseBtn"));
        CloseBtn->setMinimumSize(QSize(0, 0));
        CloseBtn->setMaximumSize(QSize(50, 50));
        CloseBtn->setStyleSheet(QString::fromUtf8(""));
        CloseBtn->setIconSize(QSize(16, 16));

        gridLayout->addWidget(CloseBtn, 0, 6, 1, 1);

        MaxBtn = new QPushButton(Title);
        MaxBtn->setObjectName(QString::fromUtf8("MaxBtn"));
        MaxBtn->setMinimumSize(QSize(50, 50));
        MaxBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(MaxBtn, 0, 3, 1, 1);

        FullScreenBtn = new QPushButton(Title);
        FullScreenBtn->setObjectName(QString::fromUtf8("FullScreenBtn"));
        FullScreenBtn->setMinimumSize(QSize(50, 50));
        FullScreenBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(FullScreenBtn, 0, 4, 1, 1);


        retranslateUi(Title);

        QMetaObject::connectSlotsByName(Title);
    } // setupUi

    void retranslateUi(QWidget *Title)
    {
        Title->setWindowTitle(QCoreApplication::translate("Title", "Form", nullptr));
        MenuBtn->setText(QCoreApplication::translate("Title", "PlayerDemo", nullptr));
        MinBtn->setText(QString());
        MovieNameLab->setText(QCoreApplication::translate("Title", "movie_name", nullptr));
        CloseBtn->setText(QString());
        MaxBtn->setText(QString());
        FullScreenBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Title: public Ui_Title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H
