#ifndef PLAY_ITEM_H
#define PLAY_ITEM_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>
#include"vedioplayer.h"
#include"mainwid.h"
//https://api.bilibili.com/x/web-interface/wbi/index/top/feed/rcmd?web_location=1430650&y_num=3&fresh_type=4&feed_version=V8&fresh_idx_1h=1&fetch_row=4&fresh_idx=1&brush=1&homepage_ver=1&ps=12&last_y_num=4&screen=838-799&seo_info=&last_showlist=av_1455230802,av_112557587173322,av_1955232185,av_1354812957,av_1305507438,ad_5614,av_1605230376,av_n_1705582081,av_n_1205725295,av_n_1655658896&uniq_id=1102829278417&w_rid=536903938c5d26f5a2c9d4da8207288d&wts=1718420283
//https://api.bilibili.com/x/web-show/wbi/res/locs?pf=0&ids=3449
//https://api.live.bilibili.com/xlive/web-interface/v1/webMain/getMoreRecList?platform=web
struct PlayData {
    QString pic;
    QString title;
    QString name;
    QString video_url;
    QString id;
    int64_t duration;
    int64_t pubdate;
    int64_t danmu;
    int64_t view;
    int64_t like;

    bool fromJson(const QJsonObject & obj);
};

class PlayItem : public QWidget
{
    Q_OBJECT
public:
    explicit PlayItem(QWidget *parent = nullptr);
    void init(const PlayData & data);
signals:
    void titleClicked(const QString &url,int64_t totaltime); // 固定 URL
public:
    PlayData data_;
private:
    //vedioplayer *videoPlayer_;
    QString videoUrl_;
};

#endif // PLAY_ITEM_H
