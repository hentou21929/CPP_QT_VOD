#include "my_line_edit2.h"

MyLineEdit2::MyLineEdit2(QWidget *parent) : QLineEdit(parent){

}

void MyLineEdit2::focusInEvent(QFocusEvent *ev) {
    focused_ = true;
    emit focusChanged(true);
    QLineEdit::focusInEvent(ev);
}

void MyLineEdit2::focusOutEvent(QFocusEvent *ev) {
    focused_ = false;
    emit focusChanged(false);
    QLineEdit::focusOutEvent(ev);
}
