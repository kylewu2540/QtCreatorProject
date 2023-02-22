#include "registerwindow.h"
#include "./ui_registerwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVariant>
#include <QMessageBox>
#include <QObject>
#include <string>
#include <regex>
#include <iostream>
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString full_name = ui->fullName->text();
    QString username = ui->username->text();
    QString email = ui->email->text();
    QString password  = ui->password->text();
    QString confirm_password = ui->confirmPassword->text();

    bool val = validateRegistration(full_name, username, email, password, confirm_password);

    if(!val)
    {
        QMessageBox::critical(nullptr, "Error", "Failed to execute query");
    }
    else
    {
        addToDatabase(full_name, username, email, password, confirm_password);
    }

}

bool RegisterWindow::validateRegistration(QString full_name, QString username, QString email, QString password, QString confirm_password)
{
    bool operation  = true;
    string email_regex = "^([a-zA-Z0-9_\\-\\.]+)@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z0-9\\-]+\\.)+[a-zA-Z]{2,}))$";
    string fn_regex = "^[a-zA-Z\\-\\' ]+$";
    string pw_regex = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$";
    string un_regex = "^(?![_\\-])(?!.*[_\\-]{2})[a-zA-Z0-9_\\-]+(?![_\\-])$";

    regex email_pattern(email_regex);
    regex fn_pattern(fn_regex);
    regex un_pattern(un_regex);
    regex pw_pattern(pw_regex);

    QObject::connect(ui->fullName, &QLineEdit::textChanged, [&](){
        if (regex_match(full_name.toStdString(), fn_pattern)) {
            QMessageBox::warning(nullptr, "Error", "Full Name field is empty.");
            operation = false;
        }
    });

    QObject::connect(ui->username, &QLineEdit::textChanged, [&](){
        if (regex_match(username.toStdString(), un_pattern)) {
            QMessageBox::warning(nullptr, "Error", "Username field is empty.");
            operation = false;
        }
    });

    QObject::connect(ui->email, &QLineEdit::textChanged, [&](){
        if (regex_match(email.toStdString(), email_pattern)) {
            QMessageBox::warning(nullptr, "Error", "Email field is empty.");
            operation = false;
        }
    });

    QObject::connect(ui->password, &QLineEdit::textChanged, [&](){
        if (regex_match(password.toStdString(), pw_pattern)) {
            QMessageBox::warning(nullptr, "Error", "Password field is empty.");
            operation = false;
        }
    });

    QObject::connect(ui->confirmPassword, &QLineEdit::textChanged, [&](){
        if (password != confirm_password) {
            QMessageBox::warning(nullptr, "Error", "Confirm Password field must match the password field");
            operation = false;
        }
    });

    return operation;
}

void RegisterWindow::addToDatabase(QString full_name, QString username, QString email, QString password, QString confirm_password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("databaseOne");
    db.setUserName("your_username");
    db.setPassword("your_password");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to connect to database");
        return;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO users (full_name, username, email, password, confirm_password) VALUES (:full_name, :username, :email, :password, :confirm_password)");
    query.bindValue(":full_name", QVariant(full_name));
    query.bindValue(":username", QVariant(username));
    query.bindValue(":email", QVariant(email));
    query.bindValue(":password", QVariant(password));
    query.bindValue(":confirm_password", QVariant(confirm_password));

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    // Close the database connection
    db.close();
}

