#include <QScreen>
#include <QPainterPath>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QLineEdit>
#include <QButtonGroup>
#include <QStackedLayout>
#include <QDockWidget>
#include <QStackedLayout>
#include <QApplication>
#include <QWindow>
#include <memory>
#include "left_widget.h"
#include "main_window.h"
#include "my_line_edit.h"
#include "my_push_button.h"
#include "event_widget.h"
#include "recommand_panel.h"
#include "close_confirm_dlg.h"
#include "live_push_window.h"
#include "app.h"

#include "obs.h"
#define OFFSET 13

#define FRAMESHAPE 10

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowMinMaxButtonsHint);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(1100, 700);
}

MainWindow::~MainWindow() {

}

void MainWindow::resizeEvent(QResizeEvent *ev) {
    QWidget::resizeEvent(ev);
    live_refresh_outter_->move(live_widget_->width() - 58, live_widget_->height() - 98);
    live_btn_outter_->move(live_widget_->width() - 58, live_widget_->height() - 150);
    emit resized(ev);
}

void MainWindow::showShadow(bool show) {
    if (show) {
        if (shade_window_) {
            return;
        }

        shade_window_ = std::make_shared<QWidget>(this);
        QString str("QWidget{background-color:rgba(0,0,0,0.6);border-radius:8px;}");   //0.6代表透明度，根据需要自行调整
        shade_window_->setStyleSheet(str);
        if(Qt::WindowMaximized != windowState()) {
            shade_window_->setGeometry(15, 15, width()-30, height()-27);    //遮罩窗口位置
        } else {
            shade_window_->setGeometry(0, 0, width(), height() + 5);    //遮罩窗口位置
        }

        shade_window_->show();     //显示
    } else {
        shade_window_ = nullptr;
    }
}


void MainWindow::init() {
    QList<QScreen*> screen = QGuiApplication::screens();
    assert(screen[0] != nullptr);
    move((screen[0]->geometry().width()-width())/2,(screen[0]->geometry().height()-height())/2);

    EventWidget *main_widget = new EventWidget;
    main_widget->setStyleSheet("QWidget{border:none;}");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->setContentsMargins(0,0,0,0);
    main_layout->setSpacing(0);
    {
        //创建左边
        LeftWidget *left_widget = new LeftWidget;
        left_widget->setFixedWidth(65);
        left_widget->init();
        main_layout->addWidget(left_widget, 0);
    }
    {
        //创建右边
        QWidget *right_widget = new QWidget;
        right_widget->setStyleSheet("QWidget{background-color:rgb(23,24,26);"
                                    "border-top-right-radius:8px;"
                                    "border-bottom-right-radius:8px}");
        QVBoxLayout *layout = new QVBoxLayout;
        layout->setContentsMargins(0,0,0,0);

        // 设置 right_widget 的最小尺寸
        //right_widget->setMinimumSize(100, 1790);
        //right_widget->setCursor(Qt::PointingHandCursor);
        right_widget->setLayout(layout);
        {
            QWidget *top_bar = new QWidget;
            top_bar->setStyleSheet("QWidget{border-bottom:1px solid rgb(35,37,39)}");
            top_bar->setFixedHeight(75);
            QHBoxLayout *top_bar_layout = new QHBoxLayout;
            top_bar_layout->setContentsMargins(43, 10, 10, 10);
            {

            }

            top_bar_layout->addSpacing(50);
            top_bar_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
            {
                tab_btns_ = new QWidget;

                QVBoxLayout *tab_btns_main_layout = new QVBoxLayout;
                tab_btns_main_layout->setContentsMargins(0,0,0,0);

                QHBoxLayout *tab_btns_layout = new QHBoxLayout;
                tab_btns_layout->setSpacing(30);
                tab_btns_layout->setContentsMargins(0,0,0,0);

                QButtonGroup *btn_group = new QButtonGroup;
                btn_group->setExclusive(true);
                QPushButton *live_btn = new QPushButton("直播");
                live_btn->setStyleSheet("QPushButton{"
                                        "font-family:'微软雅黑';"
                                        "font-size:15px;"
                                        "font-weight:200;"
                                        "font-style:bold;"
                                        "border:none;"
                                        "}"
                                        "QPushButton:hover{"
                                        "color:#d44e7d;"
                                        "}"
                                        "QPushButton:checked{"
                                        "color:#d44e7d;"
                                        "}");
                live_btn->setCursor(Qt::PointingHandCursor);

                tab_btns_layout->addWidget(live_btn, 0, Qt::AlignLeft);
                connect(live_btn, &QPushButton::clicked, [this, live_btn]() {
                    QPropertyAnimation *anim = new QPropertyAnimation(underline_widget_, "pos", nullptr);
                    anim->setDuration(200);
                    anim->setStartValue(underline_widget_->pos());
                    anim->setEndValue(QPoint(live_btn->pos().x() + 5, underline_widget_->pos().y()));
                    anim->start();

                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        center_stacked_layout_->setCurrentIndex(0);
                        live_refresh_outter_->move(live_widget_->width() - 58, live_widget_->height() - 98);
                        live_btn_outter_->move(live_widget_->width() - 58, live_widget_->height() - 150);
                        // live_btn_start_->move(100, 100);
                    });
                });


                recommand_btn_ = new QPushButton("推荐");
                recommand_btn_->setStyleSheet("QPushButton{"
                                        "font-family:'微软雅黑';"
                                        "font-size:15px;"
                                        "font-weight:200;"
                                        "font-style:bold;"
                                        "border:none;"
                                        "}"
                                        "QPushButton:hover{"
                                        "color:#d44e7d;"
                                        "}"
                                         "QPushButton:checked{"
                                         "color:#d44e7d;"
                                         "}");
                recommand_btn_->setCursor(Qt::PointingHandCursor);
                tab_btns_layout->addWidget(recommand_btn_, 0, Qt::AlignLeft);
                connect(recommand_btn_, &QPushButton::clicked, [this]() {
                    QPropertyAnimation *anim = new QPropertyAnimation(underline_widget_, "pos", nullptr);
                    anim->setDuration(200);
                    anim->setStartValue(underline_widget_->pos());
                    anim->setEndValue(QPoint(recommand_btn_->pos().x() + 5, underline_widget_->pos().y()));
                    anim->start();
                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        center_stacked_layout_->setCurrentIndex(1);
                    });
                });


                QPushButton *hot_btn = new QPushButton("热门");
                hot_btn->setStyleSheet("QPushButton{"
                                             "font-family:'微软雅黑';"
                                             "font-size:15px;"
                                             "font-weight:200;"
                                             "font-style:bold;"
                                             "border:none;"
                                             "}"
                                             "QPushButton:hover{"
                                             "color:#d44e7d;"
                                             "}"
                                           "QPushButton:checked{"
                                           "color:#d44e7d;"
                                           "}");
                hot_btn->setCursor(Qt::PointingHandCursor);
                tab_btns_layout->addWidget(hot_btn, 0, Qt::AlignLeft);
                connect(hot_btn, &QPushButton::clicked, [this, hot_btn]() {
                    QPropertyAnimation *anim = new QPropertyAnimation(underline_widget_, "pos", nullptr);
                    anim->setDuration(200);
                    anim->setStartValue(underline_widget_->pos());
                    anim->setEndValue(QPoint(hot_btn->pos().x() + 5, underline_widget_->pos().y()));
                    anim->start();
                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        center_stacked_layout_->setCurrentIndex(2);
                    });
                });

                QPushButton *perchase_btn = new QPushButton("追番");
                perchase_btn->setStyleSheet("QPushButton{"
                                       "font-family:'微软雅黑';"
                                       "font-size:15px;"
                                       "font-weight:200;"
                                       "font-style:bold;"
                                       "border:none;"
                                       "}"
                                       "QPushButton:hover{"
                                       "color:#d44e7d;"
                                       "}"
                                            "QPushButton:checked{"
                                            "color:#d44e7d;"
                                            "}");
                perchase_btn->setCursor(Qt::PointingHandCursor);
                tab_btns_layout->addWidget(perchase_btn, 0, Qt::AlignLeft);
                connect(perchase_btn, &QPushButton::clicked, [this, perchase_btn]() {
                    QPropertyAnimation *anim = new QPropertyAnimation(underline_widget_, "pos", nullptr);
                    anim->setDuration(200);
                    anim->setStartValue(underline_widget_->pos());
                    anim->setEndValue(QPoint(perchase_btn->pos().x() + 5, underline_widget_->pos().y()));
                    anim->start();
                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        center_stacked_layout_->setCurrentIndex(3);
                    });
                });

                QPushButton *movie_btn = new QPushButton("影视");
                movie_btn->setStyleSheet("QPushButton{"
                                            "font-family:'微软雅黑';"
                                            "font-size:15px;"
                                            "font-weight:200;"
                                            "font-style:bold;"
                                            "border:none;"
                                            "}"
                                            "QPushButton:hover{"
                                            "color:#d44e7d;"
                                            "}"
                                         "QPushButton:checked{"
                                         "color:#d44e7d;"
                                         "}");
                movie_btn->setCursor(Qt::PointingHandCursor);
                tab_btns_layout->addWidget(movie_btn, 0, Qt::AlignLeft);
                connect(movie_btn, &QPushButton::clicked, [this, movie_btn]() {
                    QPropertyAnimation *anim = new QPropertyAnimation(underline_widget_, "pos", nullptr);
                    anim->setDuration(200);
                    anim->setStartValue(underline_widget_->pos());
                    anim->setEndValue(QPoint(movie_btn->pos().x() + 5, underline_widget_->pos().y()));
                    anim->start();
                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        center_stacked_layout_->setCurrentIndex(4);
                    });
                });

                live_btn->setCheckable(true);
                recommand_btn_->setCheckable(true);
                hot_btn->setCheckable(true);
                perchase_btn->setCheckable(true);
                movie_btn->setCheckable(true);

                btn_group->addButton(live_btn, 0);
                btn_group->addButton(recommand_btn_, 1);
                btn_group->addButton(hot_btn, 2);
                btn_group->addButton(perchase_btn, 3);
                btn_group->addButton(movie_btn, 4);

                tab_btns_main_layout->addLayout(tab_btns_layout);

                underline_widget_ = new QWidget(tab_btns_);
                underline_widget_->setFixedSize(18, 3);
                underline_widget_->setStyleSheet("QWidget{background-color:#d44e7d}");

                // underline_widget_->setVisible(true);
                recommand_btn_->setChecked(true);

                tab_btns_->setLayout(tab_btns_main_layout);
                tab_btns_->setFixedWidth(280);
                tab_btns_->setStyleSheet("QWidget{border:none;}");
                top_bar_layout->addWidget(tab_btns_, 0, Qt::AlignLeft);
            }

            {//搜索按钮
                // auto * search_widget = new EventWidget;
                // QHBoxLayout * search_layout = new QHBoxLayout;
                // search_layout->setContentsMargins(0,0,0,0);
                // search_widget->setProperty("type", QVariant("search_widget"));
                // search_widget->setStyleSheet("EventWidget{background-color:#232527;border-radius:8px;}");
                search_edt_ = new MyLineEdit;
                search_edt_->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
                search_edt_->setFixedHeight(35);
                search_edt_->setStyleSheet("QLineEdit{background-color:#232527;"
                                          "padding-left:10px;"
                                          "padding-right:50px;"
                                          "border-top-left-radius:8px;"
                                          "border-bottom-left-radius:8px;"
                                          "}"
                                          );
                search_edt_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                search_edt_->setPlaceholderText("搜索你感兴趣的视频");
                search_edt_->setMinimumWidth(270);
                connect(search_edt_, &MyLineEdit::textChanged, [this]() {
                    if (search_edt_->text().isEmpty()) {
                        clear_search_btn_->setVisible(false);
                    } else {
                        clear_search_btn_->setVisible(true);
                    }
                });
                connect(search_edt_, &MyLineEdit::mousePressed, [this, top_bar_layout]() {
                    if (search_edt_->isFocused()) {
                        return;
                    }
                    search_edt_->setFocus(true);
                    tab_btns_->hide();
                    QPropertyAnimation *anim = new QPropertyAnimation(search_edt_, "geometry", nullptr);
                    anim->setDuration(200);
                    int pwidth = search_edt_->parentWidget()->width();
                    QRect finalRect = search_edt_->geometry();
                    anim->setStartValue(search_edt_->geometry());
                    int final_width = search_edt_->width() + 200;

                    finalRect.setRect(pwidth/2-final_width/2, finalRect.top(), final_width, finalRect.height());
                    search_btn_->move(finalRect.width() - 30, 8);
                    clear_search_btn_->move(finalRect.width() - 50, 10);
                    anim->setEndValue(finalRect);
                    anim->start();
                    top_bar_layout->update();
                    search_edt_->setStyleSheet("QLineEdit{border:1px solid #d44e7d;"
                                              "border-top-left-radius:8px;"
                                              "padding-left:10px;"
                                              "padding-right:50px;"
                                              "border-bottom-left-radius:8px;"
                                              "}"
                                              );
                    QRect search_edt_rect = search_edt_->geometry();

                    // qDebug() << "top:" << pr;

                    connect(anim, &QPropertyAnimation::finished, [this]() {
                        auto pr = search_edt_->pos();
                        auto pr2 = search_edt_->parentWidget()->parentWidget()->pos();

                        if(Qt::WindowMaximized == windowState()) {
                            pr.setX(pr.x() + pr2.x());
                        } else {
                            pr.setX(pr.x() + pr2.x() + OFFSET);
                        }
                        pr.setY(pr.y() + 50);
                        search_dropdown_list_->setFixedWidth(search_edt_->width());
                        search_dropdown_list_->move(pr);
                        search_dropdown_list_->setVisible(true);
                    });
                });

                search_btn_ = new QPushButton(search_edt_);
                search_btn_->setFixedSize(20, 20);
                search_btn_->setStyleSheet("QPushButton{background-color:#232527;border-image:url(:/res/images/search-norm.png);padding-right:20px;}"
                                          "QPushButton:hover{border-image:url(:res/images/search-hover.png)}");
                search_btn_->setCursor(Qt::PointingHandCursor);

                clear_search_btn_ = new QPushButton(search_edt_);
                clear_search_btn_->setFixedSize(13, 13);
                clear_search_btn_->setStyleSheet("QPushButton{background-color:#232527;border-image:url(:/res/images/close_search1.png);}");
                clear_search_btn_->setCursor(Qt::PointingHandCursor);
                clear_search_btn_->hide();
                connect(clear_search_btn_, &QPushButton::clicked, [this]() {
                    search_edt_->clear();
                });

                top_bar_layout->addWidget(search_edt_, 1, Qt::AlignVCenter|Qt::AlignRight);

                search_dropdown_list_ = new QWidget(this);
                search_dropdown_list_->setVisible(false);
                search_dropdown_list_->setStyleSheet("QWidget{border:1px solid rgb(35,37,39);border-radius:6px;background-color:rgb(23,24,26);}");
                search_dropdown_list_->setFixedSize(380, 300);

                {
                    QVBoxLayout *search_dd_layout = new QVBoxLayout;
                    search_dd_layout->setContentsMargins(15, 15, 15, 15);
                    QHBoxLayout *line1 = new QHBoxLayout;
                    QLabel *l = new QLabel("搜索历史");
                    l->setStyleSheet("QLabel{font-size:16px;border:none;}");
                    line1->addWidget(l, 0, Qt::AlignLeft);
                    QPushButton *b = new QPushButton("清空");
                    b->setStyleSheet("QPushButton{color:#757a81;border:none;}"
                                     "QPushButton:hover{color:#0087bd}");
                    b->setCursor(Qt::PointingHandCursor);
                    line1->addStretch(1);
                    line1->addWidget(b, 0, Qt::AlignRight);
                    search_dd_layout->addLayout(line1);
                    search_dd_layout->addStretch(1);
                    search_dropdown_list_->setLayout(search_dd_layout);
                }

            }

            {// tool btns
                QWidget *tool_btns = new QWidget;
                tool_btns->setStyleSheet("QWidget{border:none;}");
                QHBoxLayout *layout = new QHBoxLayout;
                layout->setSpacing(20);
                QPushButton *btn_minimize = new QPushButton;
                btn_minimize->setProperty("type", QVariant("nav_min_btn"));
                btn_minimize->setCursor(Qt::PointingHandCursor);
                btn_minimize->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                btn_minimize->setFixedSize(20, 20);
                connect(btn_minimize, &QPushButton::clicked, this, [this](){showMinimized();});

                btn_max_or_normal_ = new QPushButton;
                btn_max_or_normal_->setProperty("type", QVariant("nav_max_btn"));
                btn_max_or_normal_->setCursor(Qt::PointingHandCursor);
                btn_max_or_normal_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                btn_max_or_normal_->setFixedSize(20, 20);
                btn_max_or_normal_->setCheckable(true);
                connect(btn_max_or_normal_, &QPushButton::clicked, this, [this]() {
                    if(Qt::WindowMaximized != windowState()) {
                        btn_max_or_normal_->setChecked(true);
                        setWindowState( Qt::WindowMaximized );
                        update();
                    } else {
                        btn_max_or_normal_->setChecked(false);
                        setWindowState( Qt::WindowNoState );
                        update();
                    }

                    if (search_edt_->isFocused()) {
                        tab_btns_->show();
                        search_edt_->setFocus(false);
                        search_edt_->setStyleSheet("QLineEdit{border:none;"
                                                   "background-color:#232527;"
                                                   "border-top-left-radius:8px;"
                                                   "padding-left:10px;"
                                                   "padding-right:50px;"
                                                   "border-bottom-left-radius:8px;"
                                                   "}"
                                                   );
                        search_btn_->move(search_btn_->parentWidget()->width() - 28, 8);
                        clear_search_btn_->move(search_btn_->parentWidget()->width() - 50, 12);
                        search_dropdown_list_->setVisible(false);
                    }
                });

                QPushButton *btn_close = new QPushButton;
                btn_close->setProperty("type", QVariant("nav_close_btn"));
                btn_close->setCursor(Qt::PointingHandCursor);
                btn_close->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                btn_close->setFixedSize(20, 20);
                // connect(btn_close, &QPushButton::clicked, this, [this]() {
                //     QCoreApplication::instance()->quit();
                // });
                connect(btn_close, &QPushButton::clicked, this, [this]() {
                    auto main_window = App::getInstance().getMainWindow();
                    main_window->showShadow(true);
                    std::shared_ptr<CloseConfirmDlg> close_confirm_dlg = std::make_shared<CloseConfirmDlg>(main_window);
                    close_confirm_dlg->init();
                    close_confirm_dlg->setModal(true);
                    close_confirm_dlg->show();
                    close_confirm_dlg->move((main_window->width()-close_confirm_dlg->width())/2, (main_window->height()-close_confirm_dlg->height())/2);
                    close_confirm_dlg->exec();
                    main_window->showShadow(false);
                });

                layout->addWidget(btn_minimize);
                layout->addWidget(btn_max_or_normal_);
                layout->addWidget(btn_close);
                tool_btns->setLayout(layout);
                top_bar_layout->addWidget(tool_btns, 0, Qt::AlignRight|Qt::AlignVCenter);
            }
            top_bar->setLayout(top_bar_layout);
            layout->addWidget(top_bar, 0, Qt::AlignTop);
        }

        {
            center_stacked_layout_ = new QStackedLayout;
            center_stacked_layout_->setStackingMode(QStackedLayout::StackOne);
            live_widget_ = new QWidget;

            live_btn_outter_ = new QPushButton(live_widget_);
            live_btn_outter_->setStyleSheet("QPushButton{background-color:#242628;border-radius:8px;}QPushButton:hover{background-color:#2f3134}");
            live_btn_outter_->setFixedSize(46, 46);
            live_btn_outter_->setToolTip("我要开播");
            live_btn_start_ = new QPushButton(live_btn_outter_);
            live_btn_start_->setFixedSize(28, 28);
            live_btn_start_->setCursor(Qt::PointingHandCursor);
            live_btn_start_->move(9, 9);
            live_btn_start_->setStyleSheet("QPushButton{"
                                           "border-image:url(:res/images/bi/live1.png);"
                                           "background-color:#242628;"
                                           "}"
                                           "QPushButton:hover{"
                                           "background-color:#2f3134"
                                           "}");
            // live_btn_start_->move(live_widget_->width() - 100 , live_widget_->height() - 100);
            connect(live_btn_start_, &QPushButton::clicked, [this]() {
                LivePushWindow *live_wnd = new LivePushWindow;
                live_wnd->init();
                live_wnd->show();
            });


            live_refresh_outter_ = new QPushButton(live_widget_);
            live_refresh_outter_->setStyleSheet("QPushButton{background-color:#242628;border-radius:8px;}QPushButton:hover{background-color:#2f3134}");
            live_refresh_outter_->setFixedSize(46, 46);
            live_refresh_outter_->setToolTip("刷新");
            live_refresh_btn_ = new QPushButton(live_refresh_outter_);
            live_refresh_btn_->setFixedSize(28, 28);
            live_refresh_btn_->setCursor(Qt::PointingHandCursor);
            live_refresh_btn_->move(9, 9);
            live_refresh_btn_->setStyleSheet("QPushButton{"
                                           "border-image:url(:res/images/bi/refresh2.png);"
                                           "background-color:#242628;"
                                           "}"
                                           "QPushButton:hover{"
                                           "background-color:#2f3134"
                                           "}");

            connect(live_refresh_btn_, &QPushButton::clicked, [this]() {
                LivePushWindow *live_wnd = new LivePushWindow;
                live_wnd->show();
            });
            // w1->setStyleSheet("QWidget{background-color:red}");
            center_stacked_layout_->insertWidget(0, live_widget_);


            RecommandPanel *w2 = new RecommandPanel(right_widget);
            w2->init();
            // w2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
            // w2->setStyleSheet("QWidget{background-color:green}");
            center_stacked_layout_->insertWidget(1, w2);

            QWidget *w3 = new QWidget;
            w3->setStyleSheet("QWidget{background-color:blue}");
            center_stacked_layout_->insertWidget(2, w3);

            QWidget *w4 = new QWidget;
            w4->setStyleSheet("QWidget{background-color:yellow}");
            center_stacked_layout_->insertWidget(3, w4);

            QWidget *w5 = new QWidget;
            w5->setStyleSheet("QWidget{background-color:pink}");
            center_stacked_layout_->insertWidget(4, w5);



            center_stacked_layout_->setCurrentIndex(1);
            layout->addLayout(center_stacked_layout_);
        }

        main_layout->addWidget(right_widget, 1);
    }
    // main_widget->setContentsMargins(13, 13, 13, 13);
    main_widget->setLayout(main_layout);
    setCentralWidget(main_widget);

    connect(main_widget, &EventWidget::mousePressed, [this]() {
        if (search_edt_->isFocused()) {
            tab_btns_->show();
            search_edt_->setFocus(false);
            search_edt_->setStyleSheet("QLineEdit{border:none;"
                                       "background-color:#232527;"
                                       "border-top-left-radius:8px;"
                                       "padding-left:10px;"
                                       "padding-right:50px;"
                                       "border-bottom-left-radius:8px;"
                                       "}"
                                       );
            search_btn_->move(search_btn_->parentWidget()->width() - 28, 8);
            clear_search_btn_->move(search_btn_->parentWidget()->width() - 50, 12);
            search_dropdown_list_->setVisible(false);
        }
    });
    search_dropdown_list_->raise();
    centralWidget()->setMouseTracking(true);
    setMouseTracking(true);
}

void MainWindow::showEvent(QShowEvent *event) {
    search_btn_->move(search_btn_->parentWidget()->width() - 28, 8);
    clear_search_btn_->move(search_btn_->parentWidget()->width() - 50, 12);
    underline_widget_->move(recommand_btn_->pos().x() + 5, 35);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(Qt::WindowMaximized == windowState())
    {
        setContentsMargins(0,0,0,0);
        QWidget::paintEvent(event);
        return;
    }
    setContentsMargins(OFFSET,OFFSET,OFFSET,OFFSET);
    QPainterPath path;
    QRect rect = this->rect();
    rect.adjust(15, 15, -15, -15);

    path.addRoundedRect(rect, 10, 10);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QColor color(23, 24, 26, 255);
    for(int i = 0; i < 20; i++)
    {
        int alpha = 130 - sqrt(i)*1.1*38;
        if(alpha <= 0) {
            break;
        }

        color.setAlpha(alpha);
        QPainterPath path;
        rect.adjust(-1, -1, 1, 1);
        path.addRoundedRect(rect, 10, 10);
        painter.fillPath(path, color);
    }

    path.addRoundedRect(rect, 8, 8);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, color);
    QWidget::paintEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    cal_cursor_pos_ = CalCursorPos(event->pos(),CalCursorCol(event->pos()));
    if (event->button() == Qt::LeftButton /*&& Qt::WindowMaximized != windowState()*/) {
        if(cal_cursor_pos_ != CENTER) {
            is_dragging_ = false;
            is_scaling = true;
        } else {
            is_dragging_ = true;
            is_scaling = false;
        }
    }

    move_start_pos_ = event->globalPos();
    if(is_dragging_) {
        window_pos_ = this->frameGeometry().topLeft();//记录当前窗口位置
    } else if(is_scaling) {
        pre_geometry_rect_ = geometry();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //窗体不是最大的话就改变鼠标的形状
    if(Qt::WindowMaximized != windowState()) {
        setCursorShape(CalCursorPos(event->pos(),CalCursorCol(event->pos())));
    }
    //获取当前的点，这个点是全局的
    QPoint current_pos = QCursor::pos();
    //计算出移动的位置，当前点 - 鼠标左键按下的点
    QPoint move_size = current_pos - move_start_pos_;
    QRect temp_geometry = pre_geometry_rect_;
    if(is_scaling) {
        switch(cal_cursor_pos_) {
        case TOPLEFT:
            temp_geometry.setTopLeft(pre_geometry_rect_.topLeft()+move_size);
            break;
        case TOP:
            temp_geometry.setTop(pre_geometry_rect_.top()+move_size.y());
            break;
        case TOPRIGHT:
            temp_geometry.setTopRight(pre_geometry_rect_.topRight()+move_size);
            break;
        case LEFT:
            temp_geometry.setLeft(pre_geometry_rect_.left()+move_size.x());
            break;
        case RIGHT:
            temp_geometry.setRight(pre_geometry_rect_.right()+move_size.x());
            break;
        case BUTTOMLEFT:
            temp_geometry.setBottomLeft(pre_geometry_rect_.bottomLeft()+move_size);
            break;
        case BUTTOM:
            temp_geometry.setBottom(pre_geometry_rect_.bottom()+move_size.y());
            break;
        case BUTTOMRIGHT:
            temp_geometry.setBottomRight(pre_geometry_rect_.bottomRight()+move_size);
            break;
        default:
            break;
        }
        setGeometry(temp_geometry);
    } else if(is_dragging_) {
        QPoint relative_pos = event->globalPos() - move_start_pos_;
        move(window_pos_ + relative_pos);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    is_scaling = false;
    is_dragging_ = false;
    QApplication::restoreOverrideCursor();
}


int MainWindow::CalCursorCol(QPoint pt)
{
    return (pt.x() < FRAMESHAPE ? 1 : ((pt.x() > this->width() - FRAMESHAPE) ? 3 : 2));
}

int MainWindow::CalCursorPos(QPoint pt, int col_pos)
{
    return ((pt.y() < FRAMESHAPE ? 10 : ((pt.y() > this->height() - FRAMESHAPE) ? 30 : 20)) + col_pos);
}

void MainWindow::setCursorShape(int cal_pos)
{
    Qt::CursorShape cursor;
    switch(cal_pos) {
    case TOPLEFT:
    case BUTTOMRIGHT:
        cursor = Qt::SizeFDiagCursor;
        break;
    case TOPRIGHT:
    case BUTTOMLEFT:
        cursor = Qt::SizeBDiagCursor;
        break;
    case TOP:
    case BUTTOM:
        cursor = Qt::SizeVerCursor;
        break;
    case LEFT:
    case RIGHT:
        cursor = Qt::SizeHorCursor;
        break;
    default:
        cursor = Qt::ArrowCursor;
        break;
    }
    setCursor(cursor);
}
