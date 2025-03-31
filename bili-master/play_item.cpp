#include "play_item.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPushButton>
#include "net_image_label2.h"
#include"mainwid.h"
bool PlayData::fromJson(const QJsonObject & obj) {
    pic = obj["pic"].toString();
    title = obj["title"].toString();
    if (title.size() > 15) {
        title.insert(15, "\n");
    }
    //name = obj["owner"].toObject()["name"].toString();
    //view = obj["stat"].toObject()["view"].toInteger();
    //like = obj["stat"].toObject()["like"].toInteger();
    //danmu = obj["stat"].toObject()["danmaku"].toInteger();
    name = obj["name"].toString();
    view = obj["views"].toInteger();
    like = obj["likes"].toInteger();
    danmu = obj["danmaku"].toInteger();
    duration = obj["duration"].toInteger();
    pubdate = obj["pubdate"].toInteger();
    video_url=obj["video_url"].toString();
    id=obj["id"].toString();


    return true;
}

PlayItem::PlayItem(QWidget *parent)
    : QWidget{parent}
{}

void PlayItem::init(const PlayData & data) {
    data_ = data;
    // setFixedHeight(210);
    setMinimumHeight(210);
    {
        QVBoxLayout *vl = new QVBoxLayout;
        vl->setContentsMargins(0, 0, 0, 0);

        QStackedLayout *s = new QStackedLayout;
        s->setStackingMode(QStackedLayout::StackAll);
        NetImageLabel2 *img = new NetImageLabel2(this);
        img->set_radius(0.05);
        // 设置固定大小
        //img->setFixedSize(378, 672);
        //img->load(data_.pic + "@672w_378h_1c_!web-home-common-cover");
        img->load(data_.pic);
        s->insertWidget(0, img);

        QWidget *btns_widget = new QWidget(this);
        btns_widget->setStyleSheet("QWidget{background-color:transparent}");
        QVBoxLayout *btns_layout = new QVBoxLayout;
        btns_layout->addStretch(1);
        btns_layout->setContentsMargins(0,0,0,0);
        {
            QWidget *btns = new QWidget;
            btns->setFixedHeight(30);
            btns->setStyleSheet("QWidget{background-color:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 170), stop:1 rgba(240, 240, 240, 0));border-radius:0px;}");
            QHBoxLayout *btns_inner_layout = new QHBoxLayout;
            btns_inner_layout->setContentsMargins(5, 10, 10, 5);
            {
                QLabel *play_btn = new QLabel;
                play_btn->setFixedSize(15, 15);
                play_btn->setStyleSheet("QLabel{border-image:url(:/res/images/play-btn.png);background-color:transparent}");
                play_btn->setCursor(Qt::PointingHandCursor);
                btns_inner_layout->addWidget(play_btn, 0, Qt::AlignLeft);

                QLabel *play_count = new QLabel;
                play_count->setFixedHeight(16);
                play_count->setStyleSheet("QLabel{color:#ffffff;background-color:transparent}");
                btns_inner_layout->addWidget(play_count, 0, Qt::AlignLeft);
                play_count->setText(QString::number(data_.view));


                QLabel *comment_btn = new QLabel;
                comment_btn->setFixedSize(15, 15);
                comment_btn->setStyleSheet("QLabel{border-image:url(:/res/images/comment-count.png);background-color:transparent}");
                comment_btn->setCursor(Qt::PointingHandCursor);
                btns_inner_layout->addWidget(comment_btn, 0, Qt::AlignLeft);

                QLabel *comment_count = new QLabel;
                comment_count->setFixedHeight(16);
                comment_count->setStyleSheet("QLabel{color:#ffffff;background-color:transparent}");
                btns_inner_layout->addWidget(comment_count, 0, Qt::AlignLeft);
                comment_count->setText(QString::number(data_.danmu));
                btns_inner_layout->addStretch(1);


                QLabel *time_lbl = new QLabel;
                time_lbl->setFixedHeight(16);
                time_lbl->setStyleSheet("QLabel{color:#ffffff;background-color:transparent}");
                btns_inner_layout->addWidget(time_lbl, 0, Qt::AlignRight);
                int64_t sec = data_.duration%60;
                int64_t min = data_.duration/60;
                QString ssec;
                if (sec < 10) {
                    ssec = "0" + QString::number(sec);
                } else {
                    ssec = QString::number(sec);
                }

                QString smin;
                if (min < 10) {
                    smin = "0" + QString::number((min));
                } else {
                    smin = QString::number(min);
                }

                time_lbl->setText(smin + ":" + ssec);
            }
            btns->setLayout(btns_inner_layout);
            btns_layout->addWidget(btns);
        }
        btns_widget->setLayout(btns_layout);
        s->insertWidget(1, btns_widget);
        s->setCurrentIndex(1);
        vl->addLayout(s);
        QPushButton * title = new QPushButton;
        vl->setSpacing(5);
        {

            title->setFixedHeight(20*2);
            title->setText(data_.title);
            // title->setStyleSheet("QPushButton{font-size:15px;text-align:left;text-overflow: ellipsis;word-wrap: break-word;color:#fff;font-weight:400;font-style:bold;}"
            //                      "QPushButton:hover{color:#d44e7d}");
            title->setStyleSheet("QPushButton{font-size:15px;text-align:left;color:#fff;font-weight:400;font-style:bold;}"
                                 "QPushButton:hover{color:#d44e7d}");
            title->setCursor(Qt::PointingHandCursor);
            vl->addWidget(title, 0, Qt::AlignTop);
            {
                QHBoxLayout *l = new QHBoxLayout;
                l->setContentsMargins(0, 0, 0, 0);
                QLabel *dz = new QLabel;
                dz->setStyleSheet("QLabel{color:#c95a11;background-color:#301b10;font-size:11px;padding:4px 6px 4px 6px;border-radius:3px;}");
                if (data_.like > 10000) {
                    dz->setText(QString::number(data_.like/10000) + "万点赞");
                } else {
                    dz->setText(QString::number(data_.like) + "点赞");
                }

                l->addWidget(dz, 0, Qt::AlignLeft);

                QLabel *name = new QLabel;
                name->setStyleSheet("QLabel{color:#73787e;font-size:11px;padding:4px 6px 4px 6px;}");
                QString t;
                auto curr_t = QDateTime::currentMSecsSinceEpoch()/1000;
                int64_t epoch_sec = curr_t - data_.pubdate;
                if (epoch_sec < 60) {
                    name->setText(data_.name + " · 1分钟前");
                } else if (epoch_sec < 600) {
                    name->setText(data_.name + " · 10分钟前");
                } else if (epoch_sec < 60*60) {
                    name->setText(data_.name + " · 1小时前");
                } else if (epoch_sec < 24*60*60) {
                    name->setText(data_.name + " · " + QString::number(epoch_sec/3600) + "小时前");
                } else if (epoch_sec < 2*24*60*60) {
                    name->setText(data_.name + " · 1天前");
                } else if (epoch_sec < 30*24*60*60) {
                    name->setText(data_.name + " · " + QString::number(epoch_sec/(3600*24)) + "天前");
                } else {
                    auto t_t = QDateTime::fromSecsSinceEpoch(data_.pubdate);
                    name->setText(data_.name + " · " + QString::number(t_t.date().month()) + "-" + QString::number(t_t.date().day()));
                }

                l->addWidget(name, 0, Qt::AlignLeft);
                l->addStretch(1);
                vl->addLayout(l);
            }
        }

        // 添加 VideoPlayer
        connect(title, &QPushButton::clicked, [this]() {
            emit titleClicked(data_.video_url,data_.duration);
        });
        vl->addStretch(1);
        setLayout(vl);

    }
}


