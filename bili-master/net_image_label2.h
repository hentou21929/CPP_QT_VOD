#ifndef NET_IMAGE_LABEL2_H
#define NET_IMAGE_LABEL2_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>

class NetImageLabel2 : public QLabel
{
    Q_OBJECT
public:
    NetImageLabel2(QWidget *parent = nullptr);
    void set_radius(float percent);
    void load(const QString & url);
private:
    QString url_;
    QNetworkAccessManager manager_;
    float radius_percent_ = 0;
};

#endif // NET_IMAGE_LABEL2_H
