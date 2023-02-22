#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();
    bool validateRegistration(QString full_name, QString username, QString email, QString password, QString confirm_password);
    void addToDatabase(QString full_name, QString username, QString email, QString password, QString confirm_password);

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
