#ifndef MY_LINE_EDIT2_H
#define MY_LINE_EDIT2_H

#include <QLineEdit>
#include <QObject>
#include <QWidget>

class MyLineEdit2 : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit2(QWidget *parent = nullptr);
    void focusInEvent(QFocusEvent *) override;
    void focusOutEvent(QFocusEvent *) override;
private:
    bool focused_ = false;
signals:
    void focusChanged(bool v);
};

#endif // MY_LINE_EDIT2_H
