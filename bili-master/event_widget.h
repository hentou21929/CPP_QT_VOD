#ifndef EVENT_WIDGET_H
#define EVENT_WIDGET_H

#include <QObject>
#include <QWidget>

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
signals:
    void mousePressed();
    void mouseReleased();
};

#endif // EVENT_WIDGET_H
