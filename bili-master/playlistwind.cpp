#include "playlistwind.h"
#include "ui_playlistwind.h"

playlistwind::playlistwind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playlistwind)
{
    ui->setupUi(this);
}

playlistwind::~playlistwind()
{
    delete ui;
}
