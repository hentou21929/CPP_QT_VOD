#include "main_window.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QFontDatabase>
#include "app.h"
#include <qdir.h>
#include <Windows.h>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    AllocConsole();
    freopen("CONOUT$","w",stdout);

    qDebug()<< "dir:" << QDir::currentPath();
    {
        int id = QFontDatabase::addApplicationFont(":/res/fontawesome-webfont.ttf");
        QFontDatabase database;
        QStringList families = database.applicationFontFamilies(id);

        // 输出加载的字体名称
        foreach (const QString &family, families) {
            qDebug() << "Loaded font family:" << family;
        }

        // 创建并使用字体
        QFont font;
        font.setFamily(families.first()); // 使用加载的第一个字体
    }


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "bilibili_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QFile file(":/res/qss/default.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString qss = QString(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }

    QIcon icon(":/res/images/icon.png");
    App::getInstance().setMainWindow(new MainWindow);
    App::getInstance().getMainWindow()->setWindowIcon(icon);
    if (!App::getInstance().init()) {
        return -1;
    }
    QApplication::setWindowIcon(icon);
    App::getInstance().getMainWindow()->init();
    App::getInstance().getMainWindow()->show();
    return a.exec();
}
