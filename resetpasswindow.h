#ifndef RESETPASSWINDOW_H
#define RESETPASSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ResetPassWindow;
}

class ResetPassWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResetPassWindow(QWidget *parent = nullptr);
    ~ResetPassWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ResetPassWindow *ui;
};

#endif // RESETPASSWINDOW_H
