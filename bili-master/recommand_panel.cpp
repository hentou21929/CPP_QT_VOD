#include "recommand_panel.h"
#include <QHBoxLayout>
#include <QStackedLayout>
#include "net_image_label2.h"
#include <QStackedWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QTextBlock>
#include <QTextList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "play_item.h"
#include <QScrollArea>
#include <QEventLoop>
#include <QScrollBar>
#include <QUrlQuery>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QDebug>
#include "main_window.h"
#include "app.h"
#include"mainwid.h"
#include<QMessageBox>
#include<QDebug>
#include<QSettings>
#include "globalhelper.h"
#include "show.h"
#include <QTimer>
RecommandPanel::RecommandPanel(QWidget *parent)
    : QScrollArea{parent}
{

}

void RecommandPanel::init() {
    top_widget_ = new QWidget;
    //QNetworkRequest request(QUrl("https://api.bilibili.com/x/web-interface/wbi/index/top/feed/rcmd?fetch_idx=1"));
    QNetworkRequest request(QUrl("http://119.91.46.232:8010/api/videos"));
    manager_.setCookieJar(new QNetworkCookieJar(&manager_)); // 启用 Cookie 管理
    QNetworkReply *reply = manager_.get(request);
    connect(reply, &QNetworkReply::finished, [this, reply, request]() {
        if (reply->error() == QNetworkReply::NoError) {

            // 获取响应的 Cookie
            QList<QNetworkCookie> cookies = manager_.cookieJar()->cookiesForUrl(request.url());
            for (const QNetworkCookie &cookie : cookies) {
                qDebug() << "Cookie:" << cookie.name() << "=" << cookie.value();
            }

            auto data = reply->readAll();
            QString s = QString::fromUtf8(data);
            //qDebug() << "Response Data:" << s;
            QJsonDocument document = QJsonDocument::fromJson(s.toUtf8());
            if (!document.isObject()) {
                reply->deleteLater();
                return;
            }

            auto jdata = document["data"].toObject()["item"].toArray();
            for (int i = 0; i < jdata.size(); i++) {
                PlayData d;
                d.fromJson(jdata[i].toObject());
                datas_.push_back(d);
            }

            int rows_count = datas_.size()/4;
            if(datas_.size()%4!=0)
            {
                rows_count++;
            }

            top_widget_->setFixedHeight(rows_count * 260);
            int row=0;
            for (row = 0; row <= datas_.size()/4; row++) {
                QWidget *w = new QWidget(this);
                int original_width = parentWidget()->parentWidget()->width() - 120; // 原始宽度
                 w->setFixedHeight(230);
                //auto parent = parentWidget()->parentWidget();
                 //w->setFixedWidth(parent->width() - 120);
                // w->setFixedHeight(w->width()*16/9);
               // w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                QHBoxLayout * l = new QHBoxLayout;
                l->setSpacing(20);
                if(row == datas_.size()/4)
                {   int items_in_row = (row+1)*4-datas_.size();
                    qDebug()<<"轮换"<<row;
                    if (items_in_row == 1) {
                        w->setFixedWidth(original_width * 3 / 4); // 四分之三
                    } else if (items_in_row == 2) {
                        w->setFixedWidth(original_width / 2); // 二分之一
                    } else if (items_in_row == 3) {
                        w->setFixedWidth(original_width / 4); // 四分之一
                    }

                }else
                {
                    w->setFixedWidth(original_width );
                }
                for (int j = row*4; j < (row+1)*4 && j < datas_.size(); j++) {
                    PlayItem *item = new PlayItem(this);
                    item->init(datas_[j]);
                    connect(item, &PlayItem::titleClicked, this, &RecommandPanel::onVideoClicked);
                    l->addWidget(item);

                }
                w->setLayout(l);
                items_.push_back(w);
                layout_->addWidget(w, Qt::AlignTop);
            }

            layout_->addStretch(1);
        }
        reply->deleteLater();
        setWidget(top_widget_);
        update();
    });


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layout_ = new QVBoxLayout(top_widget_);
    top_widget_->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    layout_->setContentsMargins(20, 20, 20, 20);
    layout_->setSpacing(40);
    top_widget_->setFixedHeight(230);
    top_widget_->setLayout(layout_);
    auto scrollBar = verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar:vertical{background-color:transparent}"
                             "QScrollBar::handle{"
                             "background-color:#46494e;"
                             "border-radius:5px;"
                             "}"
                             "QScrollBar::handle:hover{"
                             "    background-color:#595d63;"
                             "}"
                             "QScrollBar::sub-page{"
                             "    background-color:transparent;"
                             "}"
                             "QScrollBar::add-page{"
                             "    background-color:transparent;"
                             "}"
                             "QScrollBar::sub-line{"
                             "    background-color:transparent;"
                             "}"
                             "QScrollBar::add-line{"
                             "    background-color:transparent;"
                             "}");
    scrollBar->setCursor(Qt::PointingHandCursor);
    scrollBar->setFixedWidth(10);

    QObject::connect(scrollBar, &QScrollBar::valueChanged, [scrollBar, this]() {
        if (scrollBar->value() == scrollBar->maximum()) {
            qDebug() << "滚动条已经滚动到末尾";
            onScrollBottom();
        }
    });

    connect(App::getInstance().getMainWindow(), &MainWindow::resized, [this](QResizeEvent *ev) {
        auto parent = parentWidget()->parentWidget();
        auto w = parent->width();
        top_widget_->setFixedWidth(w - 80);
        top_widget_->setFixedHeight(w*15/9);
        qDebug() << "size:" << parent->size();
        for (auto  item : items_) {
            // item->setFixedWidth(w - 120);
            // item->setFixedHeight(w*16/9);
        }
        // top_widget_->setStyleSheet("QWidget{border:2px solid red;}");
        update();

    });


    recmd_refresh_outter_ = new QPushButton(this);
    recmd_refresh_outter_->setStyleSheet("QPushButton{background-color:#242628;border-radius:8px;}QPushButton:hover{background-color:#2f3134}");
    recmd_refresh_outter_->setFixedSize(46, 46);
    recmd_refresh_outter_->setToolTip("刷新");
    recmd_refresh_btn_ = new QPushButton(recmd_refresh_outter_);
    recmd_refresh_btn_->setFixedSize(28, 28);
    recmd_refresh_btn_->setCursor(Qt::PointingHandCursor);
    recmd_refresh_btn_->move(9, 9);
    recmd_refresh_btn_->setStyleSheet("QPushButton{border-image:url(:res/images/bi/refresh2.png)}");
    recmd_refresh_outter_->setVisible(true);
    connect(recmd_refresh_btn_, &QPushButton::clicked, this, &RecommandPanel::refreshContent);

}
void RecommandPanel::refreshContent() {
    qDebug() << "Refreshing content...";
    qDebug()<<"清空内容前";
    qDebug() << "top_widget_ width:" << top_widget_->width();
    qDebug() << "top_widget_ height:" << top_widget_->height();
    // 输出父窗口的大小
    if (top_widget_->parentWidget()) {
        qDebug() << "Parent window size before refresh:"
                 << "width:" << top_widget_->parentWidget()->width()
                 << "height:" << top_widget_->parentWidget()->height();
    }

    clearCurrentContent(); // 清空当前内容
    qDebug()<<"清空内容后";
    qDebug() << "top_widget_ width:" << top_widget_->width();
    qDebug() << "top_widget_ height:" << top_widget_->height();
    // 输出父窗口的大小
    if (top_widget_->parentWidget()) {
        qDebug() << "Parent window size before refresh:"
                 << "width:" << top_widget_->parentWidget()->width()
                 << "height:" << top_widget_->parentWidget()->height();
    }

    init(); // 重新加载内容
}

void RecommandPanel::clearCurrentContent() {
    qDeleteAll(items_); // 删除所有子控件
    items_.clear();
    datas_.clear();

    // 清理旧的布局内容
    if (layout_) {
        QLayoutItem *item;
        while ((item = layout_->takeAt(0)) != nullptr) {
            delete item->widget(); // 删除布局中的控件
            delete item;           // 删除布局项
        }
    }

    // 不删除 top_widget_，而是清空其内容
    if (top_widget_) {
        top_widget_->setFixedHeight(0); // 重置高度
        top_widget_->update();          // 强制更新
    }

    qDebug() << "After clearCurrentContent, top_widget_ width:" << top_widget_->width();
    qDebug() << "After clearCurrentContent, top_widget_ height:" << top_widget_->height();
}
void RecommandPanel::onScrollBottom() {
    fetch_count_++;
    auto url = QUrl("https://api.bilibili.com/x/web-interface/wbi/index/top/feed/rcmd");

    // qDebug() << "url:" << request.url().toString();

    QUrlQuery query;
    query.addQueryItem("fetch_idx", QString::number(fetch_count_));
    url.setQuery(query);
    QNetworkRequest request(url);
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::AlwaysNetwork); // 禁用缓存
    request.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");
    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Cache-Control", "max-age=0");
    request.setRawHeader("Pragma", "no-cache");
    QNetworkReply *reply = manager_.get(request);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            auto data = reply->readAll();

            QString s = QString::fromUtf8(data);
            qDebug()<< s;
            QJsonDocument document = QJsonDocument::fromJson(s.toUtf8());
            if (!document.isObject()) {
                reply->deleteLater();
                return;
            }
            std::vector<PlayData> datas;
            auto jdata = document["data"].toObject()["item"].toArray();
            for (int i = 0; i < jdata.size(); i++) {
                PlayData d;
                d.fromJson(jdata[i].toObject());
                datas.push_back(d);
                datas_.push_back(d);
            }

            int rows_count = datas_.size()/4;
            top_widget_->setFixedHeight(rows_count * 260);

            for (int row = 0; row < datas.size()/4; row++) {
                QWidget *w = new QWidget(this);
                auto parent = parentWidget()->parentWidget();
                w->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                QHBoxLayout * l = new QHBoxLayout;
                l->setSpacing(20);
                for (int j = row*4; j < (row+1)*4 && j < datas.size(); j++) {
                    PlayItem *item = new PlayItem(this);
                    item->init(datas[j]);
                    l->addWidget(item);
                }
                w->setLayout(l);
                items_.push_back(w);
                layout_->addWidget(w, Qt::AlignTop);
            }
            layout_->addStretch(1);
        }
        reply->deleteLater();
        setWidget(top_widget_);
        update();
    });
}

void RecommandPanel::resizeEvent(QResizeEvent *ev) {
    recmd_refresh_outter_->setVisible(true);
    recmd_refresh_outter_->move(width() - 58, height() - 98);
}
void RecommandPanel::onVideoClicked(const QString &url,int64_t totaltime) {

    static MainWid *player = nullptr;
    QFile file(":/res/qss/ctrlbar.css");
    if (!file.exists()) {
        qDebug() << "错误：CSS文件不存在！";
        return;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "错误：无法打开CSS文件，错误码：" << file.errorString();
        return;
    }
    file.close();
    if (!player) {
        player = new MainWid;
        if (!player->Init()) {
            delete player;
            player = nullptr;
            return;
        }
        player->setAttribute(Qt::WA_DeleteOnClose);
    }

    QJsonObject json{
        {"video_url", url},
    };
    QNetworkRequest request(QUrl("http://119.91.46.232:8010/api/start_stream"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = manager_.post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, [=]() {
if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
       // qDebug() << "Server response:" << data; // 打印完整的响应数据

        QJsonObject res = QJsonDocument::fromJson(data).object();
        //qDebug() << "Parsed JSON:" << res; // 打印解析后的 JSON 对象

        if (res["message"].toString() == "Stream starting in background") {
            QString outputUrl = res["output_url"].toString();
            //qDebug() << "Output URL:" << outputUrl; // 打印 output_url 的值

            player->setUrl(outputUrl);
            //QMessageBox::critical(this, "成功", outputUrl);
        } else {
            QMessageBox::critical(this, "错误", "网络请求失败1");
        }
    } else {
        QMessageBox::critical(this, "错误", "网络请求失败");
    }
    reply->deleteLater();
    });
   // qDebug()<<"000000";

    player->show();

    //qDebug()<<"111111111";
    //qDebug()<<"totaltime=-------"<<totaltime;
    player->Setvideototaltime(totaltime);
    QEventLoop loop;
    QTimer::singleShot(2000, &loop, &QEventLoop::quit);
    loop.exec();

    player->handlePlayRequest();
    //qDebug()<<"22222222";

}
