#ifndef VEDIOPLAYER_H
#define VEDIOPLAYER_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QFileDialog>
#include <QTimer>
#include <atomic>
#include <SDL.h>
#include<iostream>
#include <thread>
#include<mutex>

extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libswscale/swscale.h>
#include <libavutil/time.h>
#include <libavutil/imgutils.h>
}

namespace Ui {
class vedioplayer;
}

class vedioplayer : public QWidget
{
    Q_OBJECT

public:
    explicit vedioplayer(QWidget *parent = nullptr);
    void setUrl(const QString &url);


    ~vedioplayer();
private slots:
    //void onVideoClicked(const QString &url);


private:
    Ui::vedioplayer *ui;






};

#endif // VEDIOPLAYER_H
