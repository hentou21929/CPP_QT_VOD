#include "app.h"
#include "obs.h"
#include <obs-module.h>

#include <QDebug>
App::App(QObject *parent)
    : QObject{parent}
{}

App App::instance_;
App & App::getInstance() {
   return instance_;
}

bool App::init() {
    return true;
}
