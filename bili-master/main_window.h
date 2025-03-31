#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPushButton>
#include "my_line_edit.h"
#include "obs.h"

class QStackedLayout;
class MyLineEdit2;

enum {
    TOPLEFT = 11,
    TOP = 12,
    TOPRIGHT = 13,
    LEFT = 21,
    CENTER = 22,
    RIGHT = 23,
    BUTTOMLEFT = 31,
    BUTTOM = 32,
    BUTTOMRIGHT = 33
};
// #include "obs_qt_display.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void paintEvent(QPaintEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void resizeEvent(QResizeEvent *ev) override;
public:
    float previewScale = 1.0;
    int previewX = 0, previewY = 0;
    int previewCX = 0, previewCY = 0;
    std::atomic<obs_scene_t *> currentScene = nullptr;
    void init();
    void showShadow(bool show);
    std::shared_ptr<QWidget> shade_window_;
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
public:
    // OBSScene GetCurrentScene()
    // {
    //     return currentScene.load();
    // }

    // void SetCurrentScene(OBSSource scene, bool force)
    // {
    //     if (!IsPreviewProgramMode()) {
    //         TransitionToScene(scene, force);
    //     } else {
    //         OBSSource actualLastScene = OBSGetStrongRef(lastScene);
    //         if (actualLastScene != scene) {
    //             if (scene)
    //                 obs_source_inc_showing(scene);
    //             if (actualLastScene)
    //                 obs_source_dec_showing(actualLastScene);
    //             lastScene = OBSGetWeakRef(scene);
    //         }
    //     }

    //     if (obs_scene_get_source(GetCurrentScene()) != scene) {
    //         for (int i = 0; i < ui->scenes->count(); i++) {
    //             QListWidgetItem *item = ui->scenes->item(i);
    //             OBSScene itemScene = GetOBSRef<OBSScene>(item);
    //             obs_source_t *source = obs_scene_get_source(itemScene);

    //             if (source == scene) {
    //                 ui->scenes->blockSignals(true);
    //                 currentScene = itemScene.Get();
    //                 ui->scenes->setCurrentItem(item);
    //                 ui->scenes->blockSignals(false);

    //                 if (vcamEnabled &&
    //                     vcamConfig.type ==
    //                         VCamOutputType::PreviewOutput)
    //                     outputHandler
    //                         ->UpdateVirtualCamOutputSource();

    //                 if (api)
    //                     api->on_event(
    //                         OBS_FRONTEND_EVENT_PREVIEW_SCENE_CHANGED);
    //                 break;
    //             }
    //         }
    //     }

    //     UpdateContextBar(true);
    //     UpdatePreviewProgramIndicators();

    //     if (scene) {
    //         bool userSwitched = (!force && !disableSaving);
    //         blog(LOG_INFO, "%s to scene '%s'",
    //              userSwitched ? "User switched" : "Switched",
    //              obs_source_get_name(scene));
    //     }
    // }

private:
    QWidget *underline_widget_ = nullptr;
    QWidget * tab_btns_ = nullptr;
    QPushButton *search_btn_ = nullptr;
    QPushButton *clear_search_btn_ = nullptr;
    QPushButton *btn_max_or_normal_ = nullptr;
    MyLineEdit *search_edt_ = nullptr;
    QWidget *search_dropdown_list_ = nullptr;
    QPushButton *recommand_btn_ = nullptr;
    QStackedLayout * center_stacked_layout_ = nullptr;
signals:
    void resized(QResizeEvent *ev);
private:
    QWidget *live_widget_ = nullptr;
    QPushButton *live_btn_start_;
    QPushButton *live_btn_outter_;

    QPushButton *live_refresh_btn_;
    QPushButton *live_refresh_outter_;

    obs_display_t *obs_live_display_ = nullptr;
};
#endif // MAIN_WINDOW_H
