#ifndef UPLOAD_H
#define UPLOAD_H

#include <QWidget>
#include<QTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
namespace Ui {
class upload;
}

class upload : public QWidget
{
    Q_OBJECT

public:
    explicit upload(QWidget *parent = nullptr);
    ~upload();
    static upload *currentInstance;
    static  void progressCallback(size_t transferred, size_t total);
    QTimer *progressTimer; // 定时器
    QString progressText;  // 当前进度文本
    int dotCount;          // 点的数量计数器
    // 更新进度的槽函数
    void updateProgress(int progress);
    void updateProgressLabel();
    void sendPostRequest(const std::string &username, const std::string &videoname, const std::string &imagename);
    QString getUsernameFromSettings();
    int getVideoDuration(const std::string& filePath, int64_t& duration);


private slots:
    void on_uploadimg_clicked();

    void on_uploadvideo_clicked();

    void on_upload_2_clicked();

      int uploadToOSS(const QString &title);

    void on_pushButton_clicked();


private:
    Ui::upload *ui;
};

#endif // UPLOAD_H
