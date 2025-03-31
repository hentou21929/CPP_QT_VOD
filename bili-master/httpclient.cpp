#include "httpclient.h"
#include <QJsonDocument>
HttpClient::HttpClient(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
}

void HttpClient::post(const QString &url, const QJsonObject &data) {
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(
        request, QJsonDocument(data).toJson()
        );

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString());
            return;
        }
        QJsonObject response = QJsonDocument::fromJson(
                                   reply->readAll()).object();
        emit responseReceived(response);
        reply->deleteLater();
    });
}
