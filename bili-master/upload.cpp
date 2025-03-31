#include "upload.h"
#include "ui_upload.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QPixmap>
#include <alibabacloud/oss/OssClient.h>
#include <alibabacloud/oss/client/ClientConfiguration.h>
#include <fstream>
#include <memory>
#include <string>
#include<QTimer>
#include <QtConcurrent>
#include <QNetworkReply>
extern "C" {
#include <libavformat/avformat.h>
}

using namespace AlibabaCloud::OSS;
QString imgfilePath;
QString  videofilePath;
int64_t duration = 0;
upload::upload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::upload)
{
    ui->setupUi(this);
    // 初始化时清空显示
    ui->img->clear();
    ui->videopath->clear();
    ui->progressLabel->close();

    //ui->videotitle->clear();
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 初始化定时器
    progressTimer = new QTimer(this);
    connect(progressTimer, &QTimer::timeout, this, &upload::updateProgressLabel);
    // 初始化进度相关变量
    progressText = "正在上传";
    dotCount = 0;
}

upload::~upload()
{
    delete ui;
}
void upload::updateProgressLabel()
{
    // 更新点的数量
    dotCount = (dotCount % 3) + 1; // 循环 1 到 3
    QString dots = QString(".").repeated(dotCount); // 生成对应数量的点
    ui->progressLabel->setText(progressText + dots); // 更新标签
}

// 图片上传按钮点击事件
void upload::on_uploadimg_clicked()
{
    // 打开图片选择对话框
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Select Image File"),
        "",
        tr("Image Files (*.png *.jpg *.jpeg *.bmp)")
        );

    if (!filePath.isEmpty()) {
        imgfilePath = filePath;

        // 加载并显示图片
        QPixmap pix(imgfilePath);
        if(pix.isNull()) {
            QMessageBox::warning(this, "Error", "Unsupported image format!");
            return;
        }

        // 缩放图片适应控件大小
        ui->img->setPixmap(pix.scaled(ui->img->size(),
                                      Qt::KeepAspectRatio,
                                      Qt::SmoothTransformation));
        ui->img->setAlignment(Qt::AlignCenter);
    }
}

// 视频上传按钮点击事件
void upload::on_uploadvideo_clicked()
{
    // 打开视频选择对话框
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Select Video File"),
        "",
        tr("Video Files (*.mp4 *.avi *.mkv *.mov)")
        );

    if (!filePath.isEmpty()) {
        videofilePath = filePath;
        ui->videopath->setText(videofilePath);
    }
}

// 上传按钮点击事件
void upload::on_upload_2_clicked()
{
    // 验证输入
    const QString title = ui->videotitle->text().trimmed();
    if(title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter video title!");
        return;
    }

    if(imgfilePath.isEmpty() && videofilePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select at least one file!");
        return;
    }
    qDebug() << "Video file path:" << videofilePath;
    // 执行上传
    // 启动定时器
    ui->progressLabel->show();
    progressTimer->start(1000); // 每秒触发一次
    const int result = uploadToOSS(title);
    // 停止定时器
    progressTimer->stop();
    ui->progressLabel->clear();

    // 处理结果
    if(result == 0) {
        QMessageBox::information(this, "Success", "All files uploaded successfully!");
        // 清空界面
        ui->img->clear();
        ui->videopath->clear();
        ui->videotitle->clear();
        imgfilePath.clear();
        videofilePath.clear();

    } else {
        qDebug() << "Image file path:" << imgfilePath;
        qDebug() << "Video file path:" << videofilePath;
        QMessageBox::critical(this, "Error", QString("Upload failed (Error code: %1)").arg(result));
    }
}

// OSS上传核心函数
int upload::uploadToOSS(const QString &title)
{
    // 配置OSS客户端
    ClientConfiguration conf;
    conf.maxConnections = 10;
    conf.requestTimeoutMs = 10000;
    conf.connectTimeoutMs = 5000;

    const std::string endpoint = "";
    const std::string accessKeyId = "";
    const std::string accessKeySecret = "";
    const std::string bucketName = "";

    OssClient client(endpoint, accessKeyId, accessKeySecret, conf);

    int errorCode = 0;

    std::string imagename;
    std::string videoname;
    // 上传图片（如果已选择）
    if (!imgfilePath.isEmpty()) {
        QFileInfo imgFileInfo(imgfilePath);
        QString imgExtension = imgFileInfo.suffix();
        const std::string objectName = (title.toStdString() + "." + imgExtension.toStdString());
        const std::string localPath = imgfilePath.toStdString();
        imagename=objectName;
        auto file = std::make_shared<std::fstream>(
            localPath,
            std::ios::in | std::ios::binary
            );
        if (!file->is_open()) {
            return -1;
        }

        std::shared_ptr<std::iostream> content(file);
        PutObjectRequest request(bucketName, objectName, content);



        auto outcome = client.PutObject(request);
        if (!outcome.isSuccess()) {
            errorCode = -2;
            qDebug() << "Image upload error:"
                     << outcome.error().Code().c_str()
                     << outcome.error().Message().c_str();
        }
    }

    // 上传视频（如果已选择）
    if (!videofilePath.isEmpty()) {
        QFileInfo videoFileInfo(videofilePath);
        QString videoExtension = videoFileInfo.suffix();
        const std::string objectName = (title.toStdString() + "." + videoExtension.toStdString());
        const std::string localPath = videofilePath.toStdString();

        auto file = std::make_shared<std::fstream>(
            localPath,
            std::ios::in | std::ios::binary
            );
        if (!file->is_open()) {
            return -3;
        }
        videoname=objectName;

        if (getVideoDuration(videofilePath.toStdString(), duration) == 0)
        {

        }else
        {
            return -6;
        }
        // 如果所有文件上传成功，发送 POST 请求

        if (errorCode == 0) {
            // 从 QSettings 获取 username
            QString username = getUsernameFromSettings();
            if (username.isEmpty()) {
                qDebug() << "Username is not set in QSettings!";
                return -5; // 返回错误码表示用户名未设置
            }

            sendPostRequest(username.toStdString(), videoname, imagename);
        }
        std::shared_ptr<std::iostream> content(file);
        PutObjectRequest request(bucketName, objectName, content);



        auto outcome = client.PutObject(request);
        if (!outcome.isSuccess()) {
            errorCode = -4;
            qDebug() << "Video upload error:"
                     << outcome.error().Code().c_str()
                     << outcome.error().Message().c_str();
        }
    }



    return errorCode;
}
// 从 QSettings 中读取 username
QString upload::getUsernameFromSettings() {
    QSettings settings; // 使用默认构造函数
    return settings.value("username", "1").toString(); // 默认值为空字符串
}
void upload::sendPostRequest(const std::string &username, const std::string &videoname, const std::string &imagename)
{
    // 创建 QNetworkAccessManager 对象
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    // 设置 URL
    QUrl url("http://119.91.46.232:8010/api/upload");
    QNetworkRequest request(url);

    // 设置请求头为 JSON 格式
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 构造 JSON 数据
    QJsonObject json;
    json["username"] = QString::fromStdString(username);
    json["videoname"] = QString::fromStdString(videoname);
    json["imagename"] = QString::fromStdString(imagename);

    duration= duration / 1000000;
    json["duration"] =  QString::number(duration);

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // 发送 POST 请求
    QNetworkReply *reply = manager->post(request, data);
    qDebug()<<"-----------duration"<<duration;

    // 连接信号槽，处理响应
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 成功响应
            QByteArray response = reply->readAll();
            qDebug() << "Server response:" << response;
        } else {
            // 错误处理
            qDebug() << "POST request failed:" << reply->errorString();
        }
        reply->deleteLater();
    });
}
int upload::getVideoDuration(const std::string& filePath, int64_t& duration) {
    AVFormatContext* formatContext = nullptr;
    if (avformat_open_input(&formatContext, filePath.c_str(), nullptr, nullptr) != 0) {
        std::cerr << "无法打开视频文件: " << filePath << std::endl;
            return -1; // 打开文件失败
    }

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        std::cerr << "无法获取流信息: " << filePath << std::endl;
                avformat_close_input(&formatContext);
        return -2; // 获取流信息失败
    }

    // 获取视频时长（单位为微秒）
    duration = formatContext->duration;

    avformat_close_input(&formatContext); // 关闭上下文
    return 0; // 成功
}
void upload::on_pushButton_clicked()
{
    this->close();
}



