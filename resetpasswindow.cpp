#include "resetpasswindow.h"
#include "./ui_resetpasswindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <string>
#include <QMessageBox>
using namespace std;

ResetPassWindow::ResetPassWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResetPassWindow)
{
    ui->setupUi(this);
}

ResetPassWindow::~ResetPassWindow()
{
    delete ui;
}

void ResetPassWindow::on_pushButton_clicked()
{
    QString email = ui->emailLineEdit->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("databaseOne");
    db.setUserName("your_username");
    db.setPassword("your_password");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to connect to database");
        return;
    }

    // Prepare the SQL query
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE email = :email");
    query.bindValue(":email", QVariant(email));

    if (query.exec()) {
        QMessageBox msgBox;
        msgBox.setText("Sucsess! Your password was reset");
        msgBox.exec();
    } else {
        // Display a login error dialog box
        QMessageBox::warning(this, "Login Error", "Invalid username or password.");
    }

    // Close the database connection
    db.close();
}

