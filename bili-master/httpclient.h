#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
class HttpClient : public QObject {
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void post(const QString &url, const QJsonObject &data);
signals:
    void responseReceived(const QJsonObject &json);
    void errorOccurred(const QString &error);
private:
    QNetworkAccessManager *manager;
};
#endif // HTTPCLIENT_H
