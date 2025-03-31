#include "net_image_label2.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPainter>

NetImageLabel2::NetImageLabel2(QWidget *parent) : QLabel(parent) {}

void NetImageLabel2::load(const QString & url) {
    url_ = url;
    QNetworkRequest request((QUrl(url_)));
    QNetworkReply *reply = manager_.get(request);
    setScaledContents(true);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QPixmap pixmap;
            if (pixmap.loadFromData(reply->readAll())) {
                QBitmap mask(pixmap.size());
                QPainter painter(&mask);
                painter.setRenderHint(QPainter::Antialiasing);
                painter.fillRect(mask.rect(), Qt::white);
                painter.setBrush(Qt::black);
                float r = std::min(pixmap.size().width() * radius_percent_, pixmap.size().height() * radius_percent_);
                painter.drawRoundedRect(mask.rect(), r, r); // Set the radius of the rounded corners
                QPixmap image = pixmap.copy();
                image.setMask(mask);
                setPixmap(image);
            }
        }
        reply->deleteLater();
    });
}

void NetImageLabel2::set_radius(float pixel) {
    radius_percent_ = pixel;
}
