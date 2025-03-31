#include <QStyleOption>
#include <QPainter>
#include "event_widget.h"

EventWidget::EventWidget(QWidget *parent)
    : QWidget{parent}
{}

void EventWidget::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    emit mousePressed();
}

void EventWidget::mouseReleaseEvent(QMouseEvent *event) {
    QWidget::mouseReleaseEvent(event);
    emit mouseReleased();
}

void EventWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    QWidget::paintEvent(event);
}
