#ifndef LEFT_WIDGET_H
#define LEFT_WIDGET_H

#include <QWidget>

class NetImageLabel;
class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = nullptr);
    void init();
public:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onUploadBtnClicked(); // 新增槽函数
signals:
private:
    NetImageLabel *my_head_img_ = nullptr;
};

#endif // LEFT_WIDGET_H
