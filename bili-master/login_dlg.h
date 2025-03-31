#ifndef LOGIN_DLG_H
#define LOGIN_DLG_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include<QLineEdit>
class MyLineEdit2;
class QStackedLayout;
class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    LoginDlg(QWidget *parent);
    void paintEvent(QPaintEvent *);
public:
    void init();
    QWidget* createPanel();
private slots:
    void handleRegister();
    void handleLogin();
    //void onRegisterReply(QNetworkReply* reply);
    //void onLoginReply(QNetworkReply* reply);
private:
    QPushButton *bk_;
    //MyLineEdit2 *password_edit_;
    MyLineEdit2 *checkcode_edit_;
    QStackedLayout *login_panels_;
    QPushButton *get_check_code_btn_;
    QNetworkAccessManager* m_manager = nullptr;
    QLineEdit* m_usernameEdit = nullptr;
    MyLineEdit2* password_edit_ = nullptr;
};

#endif // LOGIN_DLG_H
