#ifndef MY_PUSH_BUTTON_H
#define MY_PUSH_BUTTON_H

#include <QWidget>
#include <QDebug>
class MyPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent  *event) override;
signals:
};

#endif // MY_PUSH_BUTTON_H
