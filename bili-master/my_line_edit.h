#ifndef MY_LINE_EDIT_H
#define MY_LINE_EDIT_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit();
    bool isFocused() {
        return is_focused_;
    }
    void setFocus(bool v) {
        is_focused_ = v;
    }
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    bool is_focused_ = false;
signals:
    void mousePressed();
    void mouseReleased();
};

#endif // MY_LINE_EDIT_H
