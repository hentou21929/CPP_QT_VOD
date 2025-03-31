#include "vedioplayer.h"
#include "ui_vedioplayer.h"

vedioplayer::vedioplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vedioplayer)
{
    ui->setupUi(this);

}

vedioplayer::~vedioplayer()
{

    delete ui;
}
void vedioplayer::setUrl(const QString &url)
{

}
