#include "my_line_edit.h"

MyLineEdit::MyLineEdit()
{

}

void MyLineEdit::mousePressEvent(QMouseEvent * ev) {
    if (!is_focused_) {
        emit mousePressed();
    }

    // QWidget::mousePressEvent(ev);
}

void MyLineEdit::mouseReleaseEvent(QMouseEvent * ev) {
    // is_focused_ = false;
    emit mouseReleased();
    QWidget::mouseReleaseEvent(ev);
}
