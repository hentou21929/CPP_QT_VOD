#ifndef IJKMEDIAPLAYER_H
#define IJKMEDIAPLAYER_H
#include<iostream>
#include"ffmsgqueue.h"
#include <functional>
#include<mutex>
#include<thread>
#include"ff_ffplay.h"
class ijkmediaplayer
{
public:
    ijkmediaplayer();
    ~ijkmediaplayer();
    int ijkmp_create(std::function<int(void *)> msg_loop);
    int ijkmp_destroy();
    // 设置要播放的url
    int ijkmp_set_data_source(const char *url);
    // 准备播放
    int ijkmp_prepare_async();
    // 触发播放
    int ijkmp_start();
    // 停⽌
    int ijkmp_stop();
    // 暂停
    int ijkmp_pause();
    // seek到指定位置
    int ijkmp_seek_to(long msec);
    // 获取播放状态
    int ijkmp_get_state();
    // 是不是播放中
    bool ijkmp_is_playing();
    // 当前播放位置
    long ijkmp_get_current_position();
    // 总⻓度
    long ijkmp_get_duration();
    // 已经播放的⻓度
    long ijkmp_get_playable_duration();
    // 设置循环播放
    void ijkmp_set_loop(int loop);
    // 获取是否循环播放
    int ijkmp_get_loop();
    // 读取消息
    int ijkmp_get_msg(AVMessage *msg, int block);
    // 设置⾳量
    void ijkmp_set_playback_volume(float volume);
private:
    // 互斥量
    std::mutex mutex_;
    // 真正的播放器
    FFPlayer *ffplayer_ = NULL;
    //函数指针, 指向创建的message_loop，即消息循环函数
    //   int (*msg_loop)(void*);
    std::function<int(void *)> msg_loop_ = NULL; // ui处理消息的循环
    //消息机制线程
    std::thread *msg_thread_; // 执⾏msg_loop
    //   SDL_Thread _msg_thread;
    //字符串，就是⼀个播放url
    char *data_source_;
    //播放器状态，例如prepared,resumed,error,completed等
    int mp_state_;  // 播放状态
};

#endif // IJKMEDIAPLAYER_H
