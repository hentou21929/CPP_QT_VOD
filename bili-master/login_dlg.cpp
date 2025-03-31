#include "login_dlg.h"
#include <QStyleOption>
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVariant>
#include <QLabel>
#include <QStyleOption>
#include <QLineEdit>
#include <QPainter>
#include <QStackedLayout>
#include <QButtonGroup>
#include <QRegularExpression>
#include "my_line_edit2.h"
#include <QJsonDocument>  // 必须包含此头文件
#include <QJsonObject>
#include <QMessageBox>
#include <QSettings>
LoginDlg::LoginDlg(QWidget *parent) : QDialog(parent) {
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowMinMaxButtonsHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(800, 400);
    setStyleSheet("QDialog{background-color:#fff;border-radius:8px;font-color:#505050}");
}

void LoginDlg::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void LoginDlg::init() {
    m_manager = new QNetworkAccessManager(this);
    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->setContentsMargins(8, 8, 8, 8);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 5, 0, 0);

    {
        QWidget *line1 = new QWidget(this);
        QHBoxLayout *line1_layout = new QHBoxLayout;
        line1_layout->addStretch(1);

        QPushButton *close_btn = new QPushButton(this);
        close_btn->setFixedSize(25, 25);
        close_btn->setStyleSheet("QPushButton{"
                                 "  border-image:url(:/res/images/close2.png);"
                                 "}"
                                 "QPushButton:hover{"
                                 "  background-color:#f1f2f3;"
                                 "  border-radius:4px;"
                                 "}");
        close_btn->setCursor(Qt::PointingHandCursor);
        connect(close_btn, &QPushButton::clicked, [this]() {
            close();
        });
        line1_layout->addWidget(close_btn);
        line1_layout->addSpacing(5);
        line1->setLayout(line1_layout);
        main_layout->addWidget(line1, 0, Qt::AlignTop);
    }

    QWidget *line2 = new QWidget(this);
    {
        QHBoxLayout *line2_layout = new QHBoxLayout;
        line2->setLayout(line2_layout);
        line2_layout->setSpacing(40);
        line2_layout->setContentsMargins(70, 0, 60, 0);
        {//left
            QWidget *col1 = new QWidget(this);
            QVBoxLayout *col1_layout = new QVBoxLayout;
            col1_layout->setSpacing(0);
            QLabel *qrcode_text = new QLabel(this);
            qrcode_text->setText("扫描二维码登录");
            qrcode_text->setStyleSheet("QLabel{color:#505050; font-size:18px;}");
            col1_layout->addWidget(qrcode_text, 0, Qt::AlignHCenter);

            {
                QWidget *qr_widget = new QWidget(this);
                qr_widget->setFixedSize(170, 170);
                qr_widget->setStyleSheet("QWidget{border: 1px solid #e3e5e7; border-radius:6px;}");
                QLabel *qrcode_img = new QLabel(qr_widget);
                QImage *img;
                qrcode_img->move(5, 5);
                qrcode_img->setFixedSize(160, 160);
                qrcode_img->setStyleSheet("QLabel{border-image:url(:res/images/qrcode-2.png); border-radius:0px;}");
                col1_layout->addSpacing(20);
                col1_layout->addWidget(qr_widget, 0, Qt::AlignHCenter);
            }

            {
                col1_layout->addSpacing(10);
                {
                    QHBoxLayout *h = new QHBoxLayout;
                    h->setSpacing(0);

                    QLabel *tip1 = new QLabel("请使用 ", this);
                    tip1->setStyleSheet("QLabel{color:#505050;font-size:13px;}");

                    QPushButton *download_app_btn = new QPushButton("客户端");
                    download_app_btn->setStyleSheet("QPushButton{color:#ff6699;font-size:13px;}");
                    download_app_btn->setCursor(Qt::PointingHandCursor);

                    h->addStretch(1);
                    h->addWidget(tip1, 0, Qt::AlignHCenter);
                    h->addWidget(download_app_btn, 0, Qt::AlignHCenter);
                    h->addStretch(1);
                    col1_layout->addLayout(h);
                }

                QLabel *tip2 = new QLabel("扫码登录或扫码下载APP", this);
                tip2->setStyleSheet("QLabel{color:#505050;font-size:13px;}");


                col1_layout->addWidget(tip2, 0, Qt::AlignHCenter);
            }

            col1->setLayout(col1_layout);


            line2_layout->addWidget(col1, 0, Qt::AlignLeft|Qt::AlignTop);
        }

        {//middle line
            QLabel *l = new QLabel(this);
            l->setStyleSheet("QLabel{background-color:#e3e5e7}");
            l->setFixedWidth(1);
            l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
            line2_layout->addWidget(l);
        }
        {//right
            QWidget *right = new QWidget(this);
            right->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            QVBoxLayout *right_layout = new QVBoxLayout;
            right_layout->setSpacing(0);
            right_layout->setContentsMargins(0,0,0,0);
            {
                QWidget *line1 = new QWidget(this);
                QHBoxLayout *line1_layout = new QHBoxLayout;
                line1_layout->setSpacing(20);
                line1->setLayout(line1_layout);

                QButtonGroup *group = new QButtonGroup;
                QPushButton *pass_login = new QPushButton(this);
                pass_login->setText("密码登录");
                pass_login->setStyleSheet("QPushButton{"
                                          "color:#505050; "
                                          "font-size:18px;"
                                          "}"
                                          "QPushButton:hover{"
                                          "color:#ff6699;"
                                          "}"
                                          "QPushButton:checked{"
                                          "color:#ff6699;"
                                          "}");
                pass_login->setCursor(Qt::PointingHandCursor);
                pass_login->setCheckable(true);
                pass_login->setChecked(true);



                line1_layout->addWidget(pass_login, 0, Qt::AlignHCenter);

                right_layout->addWidget(line1, 0, Qt::AlignTop| Qt::AlignHCenter);
                right_layout->addSpacing(20);
            }

            login_panels_ = new QStackedLayout;

            {
                QWidget *login_by_password = new QWidget(this);
                QVBoxLayout *login_by_password_layout = new QVBoxLayout;
                login_by_password_layout->setContentsMargins(0,0,0,0);
                login_by_password->setLayout(login_by_password_layout);
                {// line2
                    QWidget *login_inputs = new QWidget(this);
                    login_inputs->setFixedHeight(94);
                    login_inputs->setStyleSheet("QWidget{border:1px solid #e3e5e7;border-radius:8px;}");
                    login_by_password_layout->addWidget(login_inputs);
                    {
                        QVBoxLayout *l = new QVBoxLayout;
                        l->setContentsMargins(0,0,0,0);
                        QLineEdit *user = new QLineEdit(this);
                        user->setObjectName("usernameInput");
                        m_usernameEdit = user;
                        QLabel *user_lbl = new QLabel("用户名", user);
                        user_lbl->setStyleSheet("QLabel{color:#505050;font-size:14px;border:none}");
                        user_lbl->move(22, 2);

                        user->setStyleSheet("QLineEdit{"
                                            "   background:transparent;"
                                            "   border:none;"
                                            "   padding-left:70px;"
                                            "   color:#2f2f2f;"
                                            "   font-size:14px;"
                                            "}"
                                            "QLineEdit::placeholder {"
                                            "   color:#000;"
                                            "}");
                        user->setPlaceholderText("请输入用户名");
                        user->setMaxLength(30);
                        password_edit_ = new MyLineEdit2(this);
                        password_edit_->setStyleSheet("QLineEdit{"
                                            "   background:transparent;"
                                            "   border:none;"
                                            "   padding-left:70px;"
                                            "   color:#2f2f2f;"
                                            "   font-size:14px;"
                                            "}"
                                            "QLineEdit::placeholder {"
                                            "   color:#000;"
                                            "}");
                        password_edit_->setPlaceholderText("请输入密码");
                        password_edit_->setMaxLength(20);
                        password_edit_->setEchoMode(QLineEdit::Password);
                        connect(password_edit_, &MyLineEdit2::focusChanged, [this](bool v) {
                            bk_->setChecked(v);
                        });

                        QLabel *password_lbl = new QLabel("密码", password_edit_);
                        password_lbl->setStyleSheet("QLabel{color:#505050;font-size:14px;border:none}");
                        password_lbl->move(22, 2);
                        {
                            QPushButton * eye = new QPushButton(password_edit_);
                            eye->setCheckable(true);
                            eye->setStyleSheet("QPushButton{"
                                               "    border-image:url(:res/images/eye-close-norm.png)"
                                               "}"
                                               "QPushButton:hover{"
                                               "    border-image:url(:res/images/eye-close-hover.png)"
                                               "}"
                                               "QPushButton:checked{"
                                               "    border-image:url(:res/images/eye-open-norm.png)"
                                               "}"
                                               "QPushButton:checked:hover{"
                                               "    border-image:url(:res/images/eye-open-hover.png)"
                                               "}");
                            eye->setFixedWidth(22);
                            eye->setCursor(Qt::PointingHandCursor);
                            eye->move(290, 2);

                            QPushButton * forget_password = new QPushButton("忘记密码？", password_edit_);
                            forget_password->setStyleSheet("QPushButton{"
                                               "    color:#ff6699;border:none"
                                                    "}");
                            forget_password->setCursor(Qt::PointingHandCursor);
                            forget_password->move(320, 2);
                        }


                        QLabel *ml = new QLabel(this);
                        ml->setStyleSheet("QLabel{background-color:#eee}");
                        ml->setFixedHeight(1);
                        ml->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                        l->setSpacing(0);
                        l->addWidget(user);
                        l->addWidget(ml);
                        l->addWidget(password_edit_);
                        login_inputs->setLayout(l);
                        login_by_password_layout->addWidget(login_inputs);
                    }
                }

                {
                    QWidget *login_btns = new QWidget(this);
                    QHBoxLayout *outter = new QHBoxLayout;
                    outter->setContentsMargins(0, 10, 0, 20);
                    {
                        QPushButton * reg_btn = new QPushButton("注册");
                        reg_btn->setStyleSheet("QPushButton{"
                                               "    color:#505050;"
                                               "    border:1px solid #e3e5e7;"
                                               "    border-radius:8px;"
                                               "}"
                                               "QPushButton:hover{"
                                               "    color:#ff6699;"
                                               "    border-color:#ff6699;"
                                               "}");
                        reg_btn->setFixedHeight(40);
                        reg_btn->setFixedWidth(180);
                        reg_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                        reg_btn->setCursor(Qt::PointingHandCursor);
                        outter->addWidget(reg_btn, 0, Qt::AlignLeft);

                        QPushButton * login_btn = new QPushButton("登录", this);
                        login_btn->setStyleSheet("QPushButton{"
                                               "    color:#fff;"
                                               "    background-color:#ff6699;"
                                               "    border:1px solid #e3e5e7;"
                                               "    border-radius:8px;"
                                               "}");
                        login_btn->setFixedHeight(40);
                        login_btn->setFixedWidth(180);
                        login_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
                        login_btn->setCursor(Qt::PointingHandCursor);
                        outter->addWidget(login_btn, 0, Qt::AlignRight);

                        // 在创建注册按钮后添加：
                        connect(reg_btn, &QPushButton::clicked, this, &LoginDlg::handleRegister);

                        // 在创建登录按钮后添加：
                        connect(login_btn, &QPushButton::clicked, this, &LoginDlg::handleLogin);
                    }
                    login_btns->setLayout(outter);
                    login_by_password_layout->addWidget(login_btns);
                }
                login_panels_->addWidget(login_by_password);
            }






            right_layout->addLayout(login_panels_);
            right_layout->addStretch(1);
            right->setLayout(right_layout);
            line2_layout->addWidget(right, Qt::AlignLeft|Qt::AlignTop);
        }


        main_layout->addWidget(line2, 0, Qt::AlignTop);

    }

    {
        QWidget *line3 = new QWidget(this);
        QVBoxLayout *line3_layout = new QVBoxLayout;
        line3->setLayout(line3_layout);
        {
            QHBoxLayout *h1 = new QHBoxLayout;
            QLabel *l = new QLabel(this);
            l->setText("");
            l->setStyleSheet("QLabel{color:#aaa;font-size:13px}");
            h1->addWidget(l, 0, Qt::AlignHCenter);
            line3_layout->addLayout(h1);
        }

        {
            QHBoxLayout *h2 = new QHBoxLayout;
            QLabel *l = new QLabel(this);
            l->setText("登录或注册完成代表你同意 ");
            l->setStyleSheet("QLabel{color:#aaa;font-size:13px}");

            QPushButton *b1 = new QPushButton(this);
            b1->setStyleSheet("QPushButton{color:#ff6699;font-size:13px;}");
            b1->setCursor(Qt::PointingHandCursor);
            b1->setText("用户协议");

            QLabel *l2 = new QLabel(this);
            l2->setText(" 和 ");
            l2->setStyleSheet("QLabel{color:#aaa;font-size:13px}");

            QPushButton *b2                = new QPushButton(this);
            b2->setStyleSheet("QPushButton{color:#ff6699;font-size:13px;}");
            b2->setCursor(Qt::PointingHandCursor);
            b2->setText("隐私政策");

            h2->addStretch(1);
            h2->addWidget(l, 0, Qt::AlignHCenter);
            h2->addWidget(b1, 0, Qt::AlignHCenter);
            h2->addWidget(l2, 0, Qt::AlignHCenter);
            h2->addWidget(b2, 0, Qt::AlignHCenter);
            h2->addStretch(1);
            line3_layout->addLayout(h2);
        }
        main_layout->addWidget(line3, 0, Qt::AlignBottom);
    }
    main_layout->addSpacing(20);
    // tab_panels->addWidget(line2);
    bk_= new QPushButton(this);
    bk_->setCheckable(true);
    bk_->setStyleSheet("QPushButton{"
                       "    border-image:url(:res/images/bk2.png)"
                       "}"
                       "QPushButton::checked{"
                       "    border-image:url(:res/images/bk1.png)"
                       "}");
    bk_->setFixedHeight(100);
    bk_->setFixedWidth(100);
    bk_->move(width() - 100, height() - 100);

    setLayout(main_layout);
}


QWidget *LoginDlg::createPanel()
{
    QWidget *main_widget = new QWidget;
    main_widget->setProperty("type", QVariant("last_tab_panel"));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->setContentsMargins(8, 8, 8, 8);
    main_layout->setSpacing(10);
    main_layout->setContentsMargins(10, 10, 10, 10);
    main_layout->addSpacing(10);
    {
        QHBoxLayout *line = new QHBoxLayout;
        line->setSpacing(10);
        QLabel *lbl_tmp1 = new QLabel("123");
        lbl_tmp1->setProperty("type", QVariant("title"));
        lbl_tmp1->setProperty("color", QVariant("white"));
        line->addWidget(lbl_tmp1, 0, Qt::AlignLeft | Qt::AlignVCenter);
        main_layout->addLayout(line);
    }

    {
        QHBoxLayout *line = new QHBoxLayout;
        line->setSpacing(10);
        QLabel *lbl_tmp2 = new QLabel(QString::fromLocal8Bit("copyright @ 2020 - 2025 westart inc."));
        lbl_tmp2->setProperty("type", QVariant("title"));
        lbl_tmp2->setProperty("color", QVariant("white"));
        line->addWidget(lbl_tmp2, 0, Qt::AlignLeft | Qt::AlignVCenter);
        main_layout->addLayout(line);
    }



    main_layout->addStretch(1);
    main_widget->setLayout(main_layout);
    return main_widget;
}

void LoginDlg::handleRegister() {
    if (!m_usernameEdit || !password_edit_) {
        QMessageBox::critical(this, "错误", "界面元素未正确初始化");
        return;
    }

    QJsonObject json{
        {"username", m_usernameEdit->text().trimmed()},
        {"password", password_edit_->text()}
    };
    //QMessageBox::information(this, m_usernameEdit->text().trimmed(),password_edit_->text());
    QNetworkRequest request(QUrl("http://119.91.46.232:8010/api/register"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_manager->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            QJsonObject res = QJsonDocument::fromJson(reply->readAll()).object();
            if (res["code"].toInt() == 200) {
                QMessageBox::information(this, "成功", "注册成功");
            } else {
                QMessageBox::critical(this, "错误", res["error"].toString());
            }
        } else {
            QMessageBox::critical(this, "错误", "网络请求失败");
        }
        reply->deleteLater();
    });
}

void LoginDlg::handleLogin() {
    if (!m_usernameEdit || !password_edit_) {
        QMessageBox::critical(this, "错误", "界面元素未正确初始化");
        return;
    }

    QJsonObject json{
        {"username", m_usernameEdit->text().trimmed()},
        {"password", password_edit_->text()}
    };

    QNetworkRequest request(QUrl("http://119.91.46.232:8010/api/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_manager->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            QJsonObject res = QJsonDocument::fromJson(reply->readAll()).object();
            if (res["code"].toInt() == 200) {
                QSettings settings;
                settings.setValue("username", m_usernameEdit->text());
                settings.setValue("token", res["token"].toString());
                this->accept();
                QMessageBox::information(this, "成功", "登录"
                                         "成功");
            } else {
                QMessageBox::critical(this, "错误", res["error"].toString());
            }
        } else {
            QMessageBox::critical(this, "错误", "网络请求失败");
        }
        reply->deleteLater();
    });
}
