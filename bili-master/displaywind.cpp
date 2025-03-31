#include "displaywind.h"
#include "ui_displaywind.h"
#include<QDebug>
displaywind::displaywind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displaywind)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QWidget {"
        "  background-color: #FFF;" // 默认背景颜色
        "  border: 1px solid #CCC;" // 边框
        "}");
}

displaywind::~displaywind()
{
    delete ui;
}

void displaywind::on_pushButton_clicked()
{
    qDebug()<<"222222222222";
}

