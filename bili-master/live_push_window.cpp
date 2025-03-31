#include "live_push_window.h"
#include "event_widget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QPainterPath>
#include <QPainter>
#include <QApplication>
#include <QComboBox>
#include <QLabel>

#include "net_image_label.h"
#include "net_image_label2.h"
#include "obs.h"
#include <obs-module.h>
#include <QWindow>

enum {
    TOPLEFT = 11,
    TOP = 12,
    TOPRIGHT = 13,
    LEFT = 21,
    CENTER = 22,
    RIGHT = 23,
    BUTTOMLEFT = 31,
    BUTTOM = 32,
    BUTTOMRIGHT = 33
};

#define FRAMESHAPE 10

LivePushWindow::LivePushWindow() {
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint|Qt::WindowMinMaxButtonsHint);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setMinimumSize(1280, 700);


    obs_startup("zh-CN", NULL, NULL);
    // struct obs_module_failure_info mfi;
    // obs_load_all_modules2(&mfi);
    obs_load_all_modules();
    obs_post_load_modules();
    std::vector<std::string> ret;

    size_t idx = 0;
    bool unversioned = true;
    const char *type;
    const char *unversioned_kind;
    while (obs_enum_input_types2(idx++, &type, &unversioned_kind)) {
        const char *name = obs_source_get_display_name(type);
        uint32_t caps = obs_get_source_output_flags(type);

        if ( (caps & OBS_SOURCE_CAP_DISABLED) != 0)
            continue;

        if ((caps & OBS_SOURCE_DEPRECATED) == 0) {

        }
        QString qname = QString::fromUtf8(name, -1);
        qDebug() << "name:" << qname;
        if (unversioned_kind) {
            qDebug() << "unversioned_kind:" << unversioned_kind;
        }
        // if (unversioned)
        //     ret.push_back(unversioned_kind);
        // else
        //     ret.push_back(type);
    }
    struct obs_video_info ovi;
    ovi.fps_den = 1;
    ovi.fps_num = 30;

    ovi.graphics_module = "libobs-opengl.dll";
    ovi.base_width = 640;
    ovi.base_height = 480;
    ovi.output_width = 640;
    ovi.output_height = 480;
    ovi.output_format = VIDEO_FORMAT_I420;
    ovi.colorspace = VIDEO_CS_DEFAULT;
    ovi.range = VIDEO_RANGE_DEFAULT;
    ovi.adapter = 0;
    ovi.gpu_conversion = true;
    ovi.scale_type = OBS_SCALE_DISABLE;

    obs_reset_video(&ovi);
    // obs_reset_audio();
}

void LivePushWindow::init() {
    EventWidget *main_widget = new EventWidget;
    main_widget->setStyleSheet("QWidget{border:none;border-radius:8px;}");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->setContentsMargins(15,5,15,15);
    main_layout->setSpacing(0);


    main_widget->setLayout(main_layout);
    setCentralWidget(main_widget);

    {
        QWidget *top_bar = new QWidget;
        top_bar->setStyleSheet("QWidget{"
                               "    border-bottom:1px solid rgb(35,37,39);"
                               "    background-color:#222222;"
                               "    border-radius:8px;"
                               "}");
        top_bar->setFixedHeight(60);
        QHBoxLayout *top_bar_layout = new QHBoxLayout;
        top_bar_layout->setSpacing(5);
        {
            QLabel *logo = new QLabel(this);
            logo->setStyleSheet("QLabel{border-image:url(:res/images/icon.png)}");
            logo->setFixedSize(20, 20);
            top_bar_layout->addWidget(logo, 0, Qt::AlignLeft);

            QLabel *logo1 = new QLabel(this);
            logo1->setStyleSheet("QLabel{color:#fff;font-weight:1000}");
            logo1->setText("直播伴侣");
            top_bar_layout->addWidget(logo1, 0, Qt::AlignLeft);


            QLabel *logo2 = new QLabel(this);
            logo2->setStyleSheet("QLabel{color:#878787;font-weight:800;font-size:12px;}");
            logo2->setText("·b站");
            top_bar_layout->addWidget(logo2, 0, Qt::AlignLeft);
        }
        top_bar_layout->addStretch();
        top_bar_layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        {

            auto data_center = new QPushButton;
            data_center->setStyleSheet("QPushButton{border-image:url(:res/images/data_center.png)}");
            data_center->setFixedSize(15, 15);
            top_bar_layout->addWidget(data_center);
            data_center->setCursor(Qt::PointingHandCursor);

            auto data_center_label = new QLabel;
            data_center_label->setText("主播中心");
            data_center_label->setStyleSheet("QLabel{font-size:12px;color:#878787}");
            top_bar_layout->addWidget(data_center_label);
            top_bar_layout->addSpacing(10);

            auto kefu = new QLabel;
            kefu->setStyleSheet("QLabel{border-image:url(:res/images/kefu.png)}");
            kefu->setFixedSize(15, 15);
            top_bar_layout->addWidget(kefu);
            top_bar_layout->addSpacing(10);
            kefu->setCursor(Qt::PointingHandCursor);

            auto msg = new QLabel;
            msg->setStyleSheet("QLabel{border-image:url(:res/images/msg2.png)}");
            msg->setFixedSize(15, 15);
            top_bar_layout->addWidget(msg);
            top_bar_layout->addSpacing(10);
            msg->setCursor(Qt::PointingHandCursor);

            auto help = new QLabel;
            help->setStyleSheet("QLabel{border-image:url(:res/images/help.png)}");
            help->setFixedSize(15, 15);
            top_bar_layout->addWidget(help);
            top_bar_layout->addSpacing(10);
            help->setCursor(Qt::PointingHandCursor);

            auto my_head_img_ = new NetImageLabel;
            my_head_img_->setFixedSize(25, 25);
            my_head_img_->load("http://i2.hdslb.com/bfs/face/22228ea27ca2f9a61dedeb7c152ba9994f0242aa.jpg");
            top_bar_layout->addWidget(my_head_img_);


            auto name = new QLabel;
            name->setText("爱学习的姜老师");
            name->setStyleSheet("QLabel{font-size:12px;color:#d8d4d4}");
            top_bar_layout->addWidget(name);

        }
        QLabel *d = new QLabel;
        d->setStyleSheet("QLabel{background-color:#333333}");
        d->setFixedWidth(1);
        d->setFixedHeight(12);
        top_bar_layout->addWidget(d);
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
            });

            QPushButton *btn_close = new QPushButton;
            btn_close->setProperty("type", QVariant("nav_close_btn"));
            btn_close->setCursor(Qt::PointingHandCursor);
            btn_close->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn_close->setFixedSize(20, 20);
            connect(btn_close, &QPushButton::clicked, this, [this]() {
                close();
            });

            layout->addWidget(btn_minimize);
            layout->addWidget(btn_max_or_normal_);
            layout->addWidget(btn_close);
            tool_btns->setLayout(layout);
            top_bar_layout->addWidget(tool_btns, 0, Qt::AlignRight|Qt::AlignVCenter);
        }
        top_bar->setLayout(top_bar_layout);
        main_layout->addWidget(top_bar, 0, Qt::AlignTop);
    }

    QHBoxLayout *line = new QHBoxLayout;
    left_panel_ = initLeft();
    center_panel_ = initCenter();
    right_panel_ = initRight();
    line->addWidget(left_panel_);
    line->addWidget(center_panel_);
    line->addWidget(right_panel_);
    main_layout->addSpacing(10);

    main_layout->addLayout(line);

    centralWidget()->setMouseTracking(true);
    setMouseTracking(true);
}

QWidget * LivePushWindow::createModeSelWidget() {
    QComboBox * mode_sel;
    return nullptr;
}

QWidget * LivePushWindow::initLeft() {
    QWidget * left = new QWidget(this);
    left->setFixedWidth(300);

    QVBoxLayout *left_layout = new QVBoxLayout;
    left_layout->setContentsMargins(5,0,5,5);
    left->setStyleSheet("QWidget{background-color:#222222;}");
    left->setLayout(left_layout);

    QWidget *scence_widget = new QWidget(this);
    scence_widget->setStyleSheet("QWidget{"
                             "  background-color:#333333;"
                             "  border-radius:8px;"
                             "}");
    scence_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *play_method = new QWidget(this);
    play_method->setStyleSheet("QWidget{"
                             "  background-color:#333333;"
                             "  border-radius:8px;"
                             "}");
    play_method->setFixedHeight(400);
    left_layout->addWidget(scence_widget, 1);
    left_layout->addWidget(play_method, 0);
    return left;
}

bool QTToGSWindow(QWindow *window, gs_window &gswindow)
{
    bool success = true;

#ifdef _WIN32
    gswindow.hwnd = (HWND)window->winId();
#elif __APPLE__
    gswindow.view = (id)window->winId();
#else
    switch (obs_get_nix_platform()) {
    case OBS_NIX_PLATFORM_X11_EGL:
        gswindow.id = window->winId();
        gswindow.display = obs_get_nix_platform_display();
        break;
#ifdef ENABLE_WAYLAND
    case OBS_NIX_PLATFORM_WAYLAND: {
        QPlatformNativeInterface *native =
            QGuiApplication::platformNativeInterface();
        gswindow.display =
            native->nativeResourceForWindow("surface", window);
        success = gswindow.display != nullptr;
        break;
    }
#endif
    default:
        success = false;
        break;
    }
#endif
    return success;
}


QWidget * LivePushWindow::initCenter() {
    QWidget * center = new QWidget(this);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    center->setSizePolicy(sizePolicy);

    QVBoxLayout *center_layout = new QVBoxLayout;
    center_layout->setContentsMargins(10,0,10,5);
    // center->setStyleSheet("QWidget{background-color:#222222;}");

    {
        QHBoxLayout *h = new QHBoxLayout;
        {
            auto header_img = new NetImageLabel2(this);
            header_img->load("http://i2.hdslb.com/bfs/face/22228ea27ca2f9a61dedeb7c152ba9994f0242aa.jpg");
            header_img->set_radius(0.2);
            header_img->setFixedSize(45, 45);
            h->addWidget(header_img, 0, Qt::AlignLeft);
        }

        {
            QWidget *info = new QWidget(this);
            QVBoxLayout *l = new QVBoxLayout;
            {
                QWidget * w = new QWidget(this);
                QHBoxLayout *line = new QHBoxLayout;
                line->setContentsMargins(0,0,0,0);
                auto name = new QLabel(this);
                name->setText("爱学习的姜老师正在直播");
                line->addWidget(name);


                QPushButton * btn =new QPushButton(this);
                btn->setStyleSheet("QPushButton{border-image:url(:res/images/bi/edit.png)}");
                btn->setFixedSize(15,15);
                btn->setCursor(Qt::PointingHandCursor);
                line->addWidget(btn);
                w->setLayout(line);
                l->addWidget(w);
            }


            auto name2 = new QLabel(this);
            name2->setText("未选分类");
            name2->setStyleSheet("QLabel{background-color:#403d3e;"
                                 "border-radius:3px;"
                                 "text-align:center;"
                                 "padding:3px;"
                                 "}");
            name2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
            l->addWidget(name2);
            info->setLayout(l);
            h->addWidget(info, 0, Qt::AlignLeft);
        }

        h->addStretch();

        {
            QWidget * type_widget = new QWidget(this);
            type_widget->setFixedHeight(32);
            // type_widget->setFixedWidth(120);
            type_widget->setStyleSheet("QWidget{"
                                       "background-color:#35373b;"
                                       "border-radius:16px;"
                                       "}");

            type_widget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            QHBoxLayout *l = new QHBoxLayout;
            l->addSpacing(10);
            QPushButton *henping_btn = new QPushButton("横屏");
            henping_btn->setStyleSheet("QPushButton{color:#fff;font-size:14px;}");
            henping_btn->setCursor(Qt::PointingHandCursor);
            l->addWidget(henping_btn);


            QLabel *div1 = new QLabel;
            div1->setStyleSheet("QLabel{background-color:#715f62}");
            div1->setFixedWidth(1);
            l->addSpacing(10);
            l->addWidget(div1);

            QPushButton *shuping_btn = new QPushButton("竖屏");
            shuping_btn->setStyleSheet("QPushButton{color:#505f62;font-size:14px;}");
            shuping_btn->setCursor(Qt::PointingHandCursor);
            l->addWidget(shuping_btn);


            QLabel *div2 = new QLabel;
            div2->setStyleSheet("QLabel{background-color:#715f62}");
            div2->setFixedWidth(1);
            l->addSpacing(10);
            l->addWidget(div2);

            QPushButton *double_btn = new QPushButton("双屏");
            double_btn->setStyleSheet("QPushButton{color:#505f62;font-size:14px;}");
            double_btn->setCursor(Qt::PointingHandCursor);
            l->addWidget(double_btn);
            l->addSpacing(10);


            // QLabel *div1 = new QLabel;
            // div1->setStyleSheet("QLabel{background-color:#715f62}");
            // div1->setFixedWidth(1);
            // l->addSpacing(10);
            // l->addWidget(div1);


            type_widget->setLayout(l);
            h->addWidget(type_widget);
        }
        center_layout->addLayout(h);
    }
    center->setLayout(center_layout);
    center->setSizePolicy(sizePolicy);


    video_widget_ = new QWidget(this);
    video_widget_->setSizePolicy(sizePolicy);
    video_widget_->setStyleSheet("QWidget{background-color:#000}");

    video_widget_->setAttribute(Qt::WA_PaintOnScreen);
    video_widget_->setAttribute(Qt::WA_StaticContents);
    video_widget_->setAttribute(Qt::WA_NoSystemBackground);
    video_widget_->setAttribute(Qt::WA_OpaquePaintEvent);
    video_widget_->setAttribute(Qt::WA_DontCreateNativeAncestors);
    video_widget_->setAttribute(Qt::WA_NativeWindow);

    center_layout->addSpacing(10);
    center_layout->addWidget(video_widget_, 1);

    gs_init_data info = {};
    info.cx = video_widget_->width();
    info.cy = video_widget_->height();
    info.format = GS_BGRA;
    info.zsformat = GS_ZS_NONE;
    if (QTToGSWindow(video_widget_->windowHandle(), info.window))
    {
        uint32_t backgroundColor = 0xFF000000;
        qDebug()<< "obs_display_create called";
        display_ = obs_display_create(&info, backgroundColor);
    }


    QWidget *control_widget = new QWidget(this);
    control_widget->setStyleSheet("QWidget{"
                             "  background-color:#141414;"
                             "  border-radius:10px;"
                             "}");
    control_widget->setFixedHeight(40);
    center_layout->addSpacing(20);
    center_layout->addWidget(control_widget, 0, Qt::AlignBottom);
    return center;
}

QWidget * LivePushWindow::initRight() {
    QWidget * right = new QWidget(this);
    right->setFixedWidth(300);
    QVBoxLayout *right_layout = new QVBoxLayout;
    right_layout->setContentsMargins(5,0,5,5);
    right->setStyleSheet("QWidget{background-color:#222222;}");
    right->setLayout(right_layout);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);
    right->setSizePolicy(sizePolicy);


    QWidget *viewer_list = new QWidget(this);
    viewer_list->setStyleSheet("QWidget{"
                             "  background-color:#333333;"
                             "  border-radius:8px;"
                             "}");

    QWidget *msg_list = new QWidget(this);
    msg_list->setStyleSheet("QWidget{"
                             "  background-color:#333333;"
                            "   border-radius:8px;"
                             "}");

    right_layout->addWidget(viewer_list, 1);
    right_layout->addWidget(msg_list, 1);
    return right;
}

#define OFFSET 0
void LivePushWindow::paintEvent(QPaintEvent *event)
{
    QRect rect = this->rect();
    if(Qt::WindowMaximized == windowState())
    {
        setContentsMargins(0,0,0,0);
        // QWidget::paintEvent(event);
        // return;
    } else {
        setContentsMargins(OFFSET,OFFSET,OFFSET,OFFSET);
        rect.adjust(15, 15, -15, -15);
    }

    QPainterPath path;

    // path.addRoundedRect(rect, 10, 10);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    // QColor color(23, 24, 26, 255);
    QColor color(34, 34, 34, 255);
    for(int i = 0; i < 20; i++)
    {
        int alpha = 130 - sqrt(i)*1.1*38;
        // if(alpha <= 0) {
        //     break;
        // }

        if (i == 0) {// 最内层255
            alpha = 255;
        }

        if (alpha <= 0){
            alpha = 0;
        }
        color.setAlpha(alpha);
        QPainterPath path;
        rect.adjust(-1, -1, 1, 1);
        path.addRoundedRect(rect, 10, 10);
        if (i == 0) {
            // QLinearGradient lineGradient(0,0,rect.width(),rect.height());
            // lineGradient.setColorAt(0.1, color);
            // lineGradient.setColorAt(1,QColor(62,38,42));
            // QBrush brush(lineGradient);
            // painter.setPen(color);
            // painter.setBrush(brush);
            // painter.drawRect(rect);
            painter.fillPath(path, color);
        } else {
            painter.strokePath(path, color);
        }
    }

    QWidget::paintEvent(event);
}

void LivePushWindow::mousePressEvent(QMouseEvent *event)
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

void LivePushWindow::mouseMoveEvent(QMouseEvent *event)
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

void LivePushWindow::mouseReleaseEvent(QMouseEvent *event)
{
    is_scaling = false;
    is_dragging_ = false;
    QApplication::restoreOverrideCursor();
}


int LivePushWindow::CalCursorCol(QPoint pt)
{
    return (pt.x() < FRAMESHAPE ? 1 : ((pt.x() > this->width() - FRAMESHAPE) ? 3 : 2));
}

int LivePushWindow::CalCursorPos(QPoint pt, int col_pos)
{
    return ((pt.y() < FRAMESHAPE ? 10 : ((pt.y() > this->height() - FRAMESHAPE) ? 30 : 20)) + col_pos);
}

void LivePushWindow::setCursorShape(int cal_pos)
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

