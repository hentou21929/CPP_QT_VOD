#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include "my_push_button.h"
#include "left_widget.h"
#include "net_image_label.h"
#include "app.h"
#include <QMainWindow>
#include "login_dlg.h"
#include"upload.h"
#include "main_window.h"
LeftWidget::LeftWidget(QWidget *parent)
    : QWidget{parent}
{
}

void LeftWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    QWidget::paintEvent(event);
}

void LeftWidget::init() {
    setStyleSheet("QWidget{background-color:rgb(30,32,34);"
                  "border-top-left-radius:8px;"
                  "border-bottom-left-radius:8px;}");


    QVBoxLayout *layout = new QVBoxLayout;
    {//构建上部分按钮
        QWidget *top_menus = new QWidget;
        QVBoxLayout *top_menus_layout = new QVBoxLayout;
        top_menus_layout->setContentsMargins(0,0,0,0);
        top_menus_layout->setSpacing(0);

        auto left_narrow_btn = new QPushButton(this);
        left_narrow_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/left.png);"
                                       "background-repeat:no-repeat;padding-top:7px;}");
        left_narrow_btn->setFixedSize(25, 25);
        top_menus_layout->addSpacing(23);
        top_menus_layout->addWidget(left_narrow_btn, 0, Qt::AlignTop|Qt::AlignHCenter);


        // top_menus_layout->addSpacing();

        MyPushButton *btn_test = new MyPushButton;
        btn_test->setFixedSize(40, 40);
        top_menus_layout->addWidget(btn_test, 0, Qt::AlignTop|Qt::AlignHCenter);

        auto home_btn = new QPushButton(this);
        home_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/home-norm.png);"
                                "padding-top:30px;"
                                "color:rgb(117,122,129);"
                                "font-style:bold;"
                                "font-size:11px;}"
                                "QPushButton:hover{border-image:url(:/res/images/home-hover.png);"
                                "padding-top:30px;"
                                "color:rgb(212,78,125);"
                                "font-style:bold;}");
        home_btn->setFixedSize(24, 42);
        home_btn->setCursor(Qt::PointingHandCursor);
        home_btn->setText("首页");
        top_menus_layout->addWidget(home_btn, 0, Qt::AlignTop|Qt::AlignHCenter);


        auto star_btn = new QPushButton(this);
        star_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/star-2.png);"
                                "padding-top:25px;"
                                "color:rgb(117,122,129);"
                                "font-style:bold;"
                                "font-size:11px;}"
                                "QPushButton:hover{border-image:url(:/res/images/star-1.png);"
                                "padding-top:25px;"
                                "color:rgb(212,78,125);"
                                "font-style:bold;}");
        star_btn->setFixedSize(24, 50);
        star_btn->setCursor(Qt::PointingHandCursor);
        star_btn->setText("精选");
        top_menus_layout->addSpacing(18);
        top_menus_layout->addWidget(star_btn, 0, Qt::AlignTop|Qt::AlignHCenter);


        auto dt_btn = new QPushButton(this);
        dt_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/dt-norm.png);"
                                "padding-top:25px;"
                                "color:rgb(117,122,129);"
                                "font-style:bold;"
                                "font-size:11px;}"
                                "QPushButton:hover{border-image:url(:/res/images/dt-hover.png);"
                                "padding-top:25px;"
                                "color:rgb(212,78,125);"
                                "font-style:bold;}");
        dt_btn->setFixedSize(24, 50);
        dt_btn->setCursor(Qt::PointingHandCursor);
        dt_btn->setText("动态");
        top_menus_layout->addSpacing(18);
        top_menus_layout->addWidget(dt_btn, 0, Qt::AlignTop|Qt::AlignHCenter);



        auto my_btn = new QPushButton(this);
        my_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/my1-norm.png);"
                              "padding-top:25px;"
                              "color:rgb(117,122,129);"
                              "font-style:bold;"
                              "font-size:11px;}"
                              "QPushButton:hover{border-image:url(:/res/images/my1-hover.png);"
                              "padding-top:25px;"
                              "color:rgb(212,78,125);"
                              "font-style:bold;}");
        my_btn->setFixedSize(24, 50);
        my_btn->setCursor(Qt::PointingHandCursor);
        my_btn->setText("我的");
        top_menus_layout->addSpacing(18);
        top_menus_layout->addWidget(my_btn, 0, Qt::AlignTop|Qt::AlignHCenter);

        top_menus_layout->addStretch(1);
        top_menus->setLayout(top_menus_layout);
        layout->addWidget(top_menus);
    }

    layout->addStretch(1);
    {
        QVBoxLayout *left_bottom_layout = new QVBoxLayout;
        left_bottom_layout->setContentsMargins(0, 0, 0, 0);
        left_bottom_layout->setSpacing(23);
        {
            QHBoxLayout *l = new QHBoxLayout;
            // l->addSpacing(5);
            my_head_img_ = new NetImageLabel;
            my_head_img_->setFixedSize(30, 30);
            my_head_img_->load("http://i2.hdslb.com/bfs/face/22228ea27ca2f9a61dedeb7c152ba9994f0242aa.jpg");
            l->addWidget(my_head_img_);
            // l->addSpacing(5);
            left_bottom_layout->addLayout(l);

            connect(my_head_img_, &NetImageLabel::clicked, [=]() {
                auto main_window = App::getInstance().getMainWindow();
                main_window->showShadow(true);
                std::shared_ptr<LoginDlg> login_dlg = std::make_shared<LoginDlg>(main_window);
                login_dlg->init();
                login_dlg->setModal(true);
                login_dlg->show();
                login_dlg->move((main_window->width()-login_dlg->width())/2, (main_window->height()-login_dlg->height())/2);
                login_dlg->exec();
                main_window->showShadow(false);
            });
        }

        {
            QHBoxLayout *l = new QHBoxLayout;
            QPushButton *upload_btn = new QPushButton;
            upload_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/upload-norm.png);"
                                  "color:rgb(117,122,129);"
                                  "font-style:bold;"
                                  "font-size:11px;}"
                                  "QPushButton:hover{border-image:url(:/res/images/upload-hover.png);"
                                  "color:rgb(212,78,125);"
                                  "font-style:bold;}");
            upload_btn->setFixedSize(24, 24);
            upload_btn->setCursor(Qt::PointingHandCursor);
            l->addWidget(upload_btn);
            upload_btn->setToolTip("投稿");
            left_bottom_layout->addLayout(l);

            // 连接信号与槽
            connect(upload_btn, &QPushButton::clicked, this, &LeftWidget::onUploadBtnClicked);
        }

        {
            QHBoxLayout *l = new QHBoxLayout;
            QPushButton *message_btn = new QPushButton;
            message_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/message-norm.png);"
                                      "color:rgb(117,122,129);"
                                      "font-style:bold;"
                                      "font-size:11px;}"
                                      "QPushButton:hover{border-image:url(:/res/images/message-hover.png);"
                                      "color:rgb(212,78,125);"
                                      "font-style:bold;}");
            message_btn->setFixedSize(20, 20);
            message_btn->setCursor(Qt::PointingHandCursor);
            l->addWidget(message_btn);
            message_btn->setToolTip("消息");
            left_bottom_layout->addLayout(l);
        }

        {
            QHBoxLayout *l = new QHBoxLayout;
            QPushButton *thume_btn = new QPushButton;
            thume_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/moon-norm.png);}"
                                     "QPushButton:hover{border-image:url(:/res/images/moon-hover.png);}"
                                     "QPushButton:checked{border-image:url(:/res/images/sun-hover.png);}"
                                     "QPushButton:checked:hover{border-image:url(:/res/images/sun-hover.png);}");
            thume_btn->setFixedSize(20, 20);
            thume_btn->setCursor(Qt::PointingHandCursor);
            thume_btn->setCheckable(true);
            thume_btn->setChecked(false);
            l->addWidget(thume_btn);
            thume_btn->setToolTip("主题");
            left_bottom_layout->addLayout(l);
        }

        {
            QHBoxLayout *l = new QHBoxLayout;
            QPushButton *setting_btn = new QPushButton;
            setting_btn->setStyleSheet("QPushButton{border-image:url(:/res/images/setting-norm.png);}"
                                       "QPushButton:hover{border-image:url(:/res/images/setting-hover.png);}");
            setting_btn->setFixedSize(22, 22);
            setting_btn->setCursor(Qt::PointingHandCursor);
            setting_btn->setCheckable(true);
            setting_btn->setChecked(false);
            l->addWidget(setting_btn);
            setting_btn->setToolTip("设置");
            left_bottom_layout->addLayout(l);
            left_bottom_layout->addSpacing(25);
        }

        layout->addLayout(left_bottom_layout);
    }
    setLayout(layout);
}
void LeftWidget::onUploadBtnClicked() {
    // 创建 upload 界面
    upload *uploadWidget = new upload(); // 动态创建 upload 窗口
    uploadWidget->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动释放内存
    uploadWidget->show(); // 显示窗口
}
