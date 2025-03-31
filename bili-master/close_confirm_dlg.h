#ifndef CLOSE_CONFIRM_DLG_H
#define CLOSE_CONFIRM_DLG_H

#include <QDialog>
#include <QObject>
#include <QPaintEvent>
#include <QButtonGroup>

class CloseConfirmDlg : public QDialog
{
    Q_OBJECT
public:
    CloseConfirmDlg(QWidget *parent = nullptr);
public:
    void init();
    void paintEvent(QPaintEvent *) override;
private:
    QButtonGroup *btn_group_;
};

#endif // CLOSE_CONFIRM_DLG_H
