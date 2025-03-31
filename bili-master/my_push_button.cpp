#include "my_push_button.h"

MyPushButton::MyPushButton(QWidget *parent)
    : QWidget{parent}
{}

void MyPushButton::enterEvent(QEnterEvent *event) {
    qDebug() << "enter";
}

void MyPushButton::leaveEvent(QEvent  *event) {
    qDebug() << "leave";
}
