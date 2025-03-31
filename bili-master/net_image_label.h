#ifndef NET_IMAGE_LABEL_H
#define NET_IMAGE_LABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>

class NetImageLabel : public QLabel
{
    Q_OBJECT
public:
    NetImageLabel();
    void load(const QString & url);
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
private:
    QString url_;
    QNetworkAccessManager manager_;
protected:
    bool pressed_ = false;
signals:
    void clicked();
};

#endif // NET_IMAGE_LABEL_H
