#ifndef FORGOTPASSWINDOW_H
#define FORGOTPASSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ForgotPassWindow;
}

class ForgotPassWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ForgotPassWindow(QWidget *parent = nullptr);
    ~ForgotPassWindow();
    int sendEmail(const std::string& recipient, const std::string& subject, const std::string& body);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ForgotPassWindow *ui;
};

#endif // FORGOTPASSWINDOW_H
