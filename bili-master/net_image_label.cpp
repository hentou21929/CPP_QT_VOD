#include "net_image_label.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QStyleOption>
#include <QPainter>

NetImageLabel::NetImageLabel() {
    setCursor(Qt::PointingHandCursor);
}

void NetImageLabel::mouseReleaseEvent(QMouseEvent *ev) {
    if (pressed_) {
        emit clicked();
    }
}

void NetImageLabel::mousePressEvent(QMouseEvent *ev) {
    if (!pressed_) {
        pressed_ = true;
    }
}

void NetImageLabel::mouseMoveEvent(QMouseEvent *ev) {

}

void NetImageLabel::load(const QString & url) {
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
                painter.drawRoundedRect(mask.rect(), pixmap.size().width(), pixmap.size().height()); // Set the radius of the rounded corners
                QPixmap image = pixmap.copy();
                image.setMask(mask);
                setPixmap(image);
            }
        }
        reply->deleteLater();
    });
}
