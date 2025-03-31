#ifndef APP_H
#define APP_H

#include <QObject>
class MainWindow;
class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);
    static App & getInstance();
    void setMainWindow(MainWindow *w) {
        main_window_ = w;
    }

    MainWindow * getMainWindow() {
        return main_window_;
    }

    bool init();
signals:

private:
    MainWindow *main_window_;
private:
    static App instance_;
};

#endif // APP_H
