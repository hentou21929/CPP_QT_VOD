#ifndef LIVE_PUSH_WINDOW_H
#define LIVE_PUSH_WINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QPaintEvent>

#include "obs.hpp"

class LivePushWindow : public QMainWindow
{
    Q_OBJECT
public:
    LivePushWindow();
    void init();
    QWidget * createModeSelWidget();
    QWidget * initLeft();
    QWidget * initCenter();
    QWidget * initRight();

    void paintEvent(QPaintEvent *ev) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    QPushButton *btn_max_or_normal_;
    QWidget *left_panel_;
    QWidget *center_panel_;
    QWidget *right_panel_;
private://窗口缩放及拖动处理
    QPoint move_start_pos_;
    QPoint window_pos_;

    int CalCursorCol(QPoint pt);    //计算鼠标X的位置
    int CalCursorPos(QPoint pt, int col_pos);    //计算鼠标的位置
    void setCursorShape(int cal_pos);    //设置鼠标对应位置的形状

    int     cal_cursor_pos_;
    bool    is_dragging_ = false;//是否在拖动窗口，不是缩放
    bool    is_scaling = false;//是否在缩放状态
    bool    prepare_scale_;//是否准备缩放（鼠标在缩放区域)
    QRect   pre_geometry_rect_;
    QPoint  mouse_pos_;

private:
    QWidget * video_widget_;
    OBSDisplay display_;
};

#endif // LIVE_PUSH_WINDOW_H
