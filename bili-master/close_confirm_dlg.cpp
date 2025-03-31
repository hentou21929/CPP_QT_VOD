#include <QVBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QPushButton>
#include <QLabel>

#include "close_confirm_dlg.h"
#include "app.h"
#include "main_window.h"
#include <QApplication>
CloseConfirmDlg::CloseConfirmDlg(QWidget *parent) : QDialog(parent) {
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowMinMaxButtonsHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(350, 250);
    setStyleSheet("QDialog{background-color:#242628;border-radius:8px;font-color:#505050}");
}

void CloseConfirmDlg::init() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(10, 10, 10, 10);
    {
        QHBoxLayout *l = new QHBoxLayout(this);
        QPushButton *outter_close_btn = new QPushButton(this);
        outter_close_btn->setFixedSize(30, 30);
        outter_close_btn->setStyleSheet(
                                 "QPushButton:hover{"
                                 "  background-color:#2f3134;border-radius:3px;"
                                 "}");
        QPushButton *close_btn = new QPushButton(outter_close_btn);
        close_btn->setFixedSize(20, 20);
        close_btn->move(4, 6);
        close_btn->setStyleSheet("QPushButton{"
                                 "  border-image:url(:/res/images/close2.png);border-radius:4px;"
                                 "}");
        close_btn->setCursor(Qt::PointingHandCursor);
        connect(outter_close_btn, &QPushButton::clicked, [this]() {
            close();
        });
        connect(close_btn, &QPushButton::clicked, [this]() {
            close();
        });

        l->addStretch(1);
        l->addWidget(outter_close_btn);
        layout->addLayout(l);
    }

    {
        QHBoxLayout *l = new QHBoxLayout(this);
        QLabel *label= new QLabel(this);
        label->setText("点击关闭按钮以后：");
        label->setStyleSheet("QLabel{font-size:14px;color:#e7e9eb;font-style:bolder;font-weight:3000;padding-left:5px;}");

        l->addSpacing(80);
        l->addWidget(label);
        layout->addLayout(l);
    }

    btn_group_ = new QButtonGroup;
    {
        QHBoxLayout *l = new QHBoxLayout;
        l->setSpacing(0);
        l->addSpacing(80);
        QPushButton *btn = new QPushButton(this);
        btn->setStyleSheet("QPushButton{"
                           "border-image:url(:/res/images/radio1.png);"
                           "}"
                           "QPushButton:hover{"
                           "border-image:url(:/res/images/radio1-hover.png);"
                           "}"
                           "QPushButton:checked{"
                           "border-image:url(:/res/images/radio2-sel-hover.png);"
                           "}"
                           "QPushButton:checked:hover{"
                           "border-image:url(:/res/images/radio2-sel-hover.png);"
                           "}");
        btn->setFixedSize(20, 20);
        btn_group_->addButton(btn, 0);
        btn->setCursor(Qt::PointingHandCursor);
        l->addWidget(btn);
        btn->setCheckable(true);
        btn->setChecked(false);

        QPushButton *btn2 = new QPushButton(this);
        btn2->setStyleSheet("QPushButton{font-size:12px;color:#a1a6ad;font-style:bolder;font-weight:1000;padding-left:10px;}");
        l->addWidget(btn2);
        btn2->setText("最小化到系统托盘");
        btn2->setCursor(Qt::PointingHandCursor);

        layout->addSpacing(10);
        layout->addLayout(l);
        l->addStretch(1);
    }

    {
        QHBoxLayout *l = new QHBoxLayout;
        l->setSpacing(0);
        l->addSpacing(80);
        QPushButton *btn = new QPushButton(this);
        btn->setStyleSheet("QPushButton{"
                           "border-image:url(:/res/images/radio1.png);"
                           "}"
                           "QPushButton:hover{"
                           "border-image:url(:/res/images/radio1-hover.png);"
                           "}"
                           "QPushButton:checked{"
                           "border-image:url(:/res/images/radio2-sel-hover.png);"
                           "}"
                           "QPushButton:checked:hover{"
                           "border-image:url(:/res/images/radio2-sel-hover.png);"
                           "}");
        btn->setFixedSize(20, 20);
        btn->setCursor(Qt::PointingHandCursor);
        l->addWidget(btn);
        btn_group_->addButton(btn, 1);
        btn->setCheckable(true);
        btn->setChecked(true);

        QPushButton *btn2 = new QPushButton(this);
        btn2->setStyleSheet("QPushButton{font-size:12px;color:#a1a6ad;font-style:bolder;font-weight:1000;padding-left:10px;}");
        l->addWidget(btn2);
        btn2->setText("退出应用");
        btn2->setCursor(Qt::PointingHandCursor);

        layout->addSpacing(10);
        layout->addLayout(l);
        l->addStretch(1);
    }

    {
        QHBoxLayout *l = new QHBoxLayout;
        l->setSpacing(0);
        l->addSpacing(80);
        QPushButton *btn = new QPushButton(this);
        btn->setStyleSheet("QPushButton{"
                           "border:1px solid #2f3134;"
                           "border-radius:3px;"
                           "border-image:none;"
                           "background-color:none;"
                           "}"
                           "QPushButton:hover{"
                           "border:1px solid #d44e7d;"
                           "}"
                           "QPushButton:checked{"
                           "border-image:url(:/res/images/sel-white.png);"
                           "background-color:#d44e7d;"
                           "}");
        btn->setFixedSize(18, 18);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setCheckable(true);
        btn->setChecked(false);
        l->addWidget(btn);
        // btn->setText("");

        QPushButton *btn2 = new QPushButton(this);
        btn2->setStyleSheet("QPushButton{font-size:12px;color:#a1a6ad;font-style:bolder;font-weight:1000;padding-left:10px;}");
        l->addWidget(btn2);
        btn2->setText("不再提示");
        btn2->setCursor(Qt::PointingHandCursor);

        layout->addSpacing(15);
        layout->addLayout(l);
        l->addStretch(1);
    }

    {
        QHBoxLayout *l = new QHBoxLayout;
        l->setContentsMargins(20, 5, 20, 5);
        l->setSpacing(0);
        QPushButton *btn = new QPushButton(this);
        btn->setStyleSheet("QPushButton{"
                           "border:1px solid #2b2d2f;"
                           "border-radius:4px;"
                           "background-color:none;"
                           "font-weight:1000;"
                           "}"
                           "QPushButton:hover{"
                           "border:none;"
                           "background-color:#2f3134;"
                           "}");

        btn->setFixedHeight(35);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setCheckable(true);
        btn->setChecked(false);
        btn->setText("取消");
        l->addWidget(btn);
        connect(btn, &QPushButton::clicked, [this]() {
            close();
        });
        // btn->setText("");

        QPushButton *btn2 = new QPushButton(this);
        btn2->setStyleSheet("QPushButton{"
                           "border-radius:4px;"
                           "background-color:#d44e7d;"
                           "font-weight:1000;"
                           "}"
                           "QPushButton:hover{"
                           "border:none;"
                           "background-color:#a73e65;"
                           "}");
        btn2->setFixedHeight(35);
        btn2->setCursor(Qt::PointingHandCursor);
        btn2->setCheckable(true);
        btn2->setChecked(false);
        btn2->setText("确定");
        connect(btn2, &QPushButton::clicked, [this]() {
            if (btn_group_->checkedId() == 0) {
                QApplication::setQuitOnLastWindowClosed(false);
                App::getInstance().getMainWindow()->showMinimized();
                close();
            } else {
                QCoreApplication::instance()->quit();
            }
        });
        l->addWidget(btn2);
        l->setSpacing(20);
        layout->addSpacing(15);
        layout->addLayout(l);
    }

    layout->addStretch(1);
    setLayout(layout);
}

void CloseConfirmDlg::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
