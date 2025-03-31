#ifndef RECOMMAND_PANEL_H
#define RECOMMAND_PANEL_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include "play_item.h"
#include <QScrollArea>
#include <QPushButton>
#include"vedioplayer.h"
#include <QNetworkReply>
#include"mainwid.h"
class RecommandPanel : public QScrollArea
{
    Q_OBJECT
public:
    explicit RecommandPanel(QWidget *parent = nullptr);
    void init();
    void resizeEvent(QResizeEvent *ev) override;
    void onVideoClicked(const QString &url,int64_t totaltime);
signals:


private slots:
    void refreshContent();
    void clearCurrentContent();
private:
    void onScrollBottom();
    QVBoxLayout *layout_;
    QNetworkAccessManager manager_;
    std::vector<PlayData> datas_;
    // QScrollArea *area_;
    QWidget *top_widget_ = nullptr;
    std::vector<QWidget*> items_;

    QPushButton *recmd_refresh_btn_;
    QPushButton *recmd_refresh_outter_;

    int32_t fetch_count_ = 1;
    MainWid *playerWindow;
};

#endif // RECOMMAND_PANEL_H
