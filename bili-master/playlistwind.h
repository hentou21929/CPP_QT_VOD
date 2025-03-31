#ifndef PLAYLISTWIND_H
#define PLAYLISTWIND_H

#include <QWidget>

namespace Ui {
class playlistwind;
}

class playlistwind : public QWidget
{
    Q_OBJECT

public:
    explicit playlistwind(QWidget *parent = nullptr);
    ~playlistwind();

private:
    Ui::playlistwind *ui;
};

#endif // PLAYLISTWIND_H
