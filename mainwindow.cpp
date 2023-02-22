#include "mainwindow.h"
#include "homewindow.h"
#include "./ui_mainwindow.h"
#include "user.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <string>
#include <QString>
#include <QVariant>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    /*
    if (username == "admin" && password == "password") {
        QMessageBox::information(this, "Login Successful", "You have been logged in.");
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }*/

    //validateLogin(username, password);
}

bool MainWindow::validateLogin(QString  username, QString password)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("databaseOne");
    db.setUserName("your_username");
    db.setPassword("your_password");
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Error", "Failed to connect to database");
        return false;
    }

    // Prepare the SQL query
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", QVariant(username));
    query.bindValue(":password", QVariant(password));

    if (query.exec() && query.first()) {
        // Create a new User object and populate it with the user's information
        User *user = new User(username, password);

        // Pass the user object to the main screen
        HomeWindow *hw = new HomeWindow(this);
        hw->show();
        this->hide();
    } else {
        // Display a login error dialog box
        QMessageBox::warning(this, "Login Error", "Invalid username or password.");
    }

    // Close the database connection
    db.close();

    return true;
}

