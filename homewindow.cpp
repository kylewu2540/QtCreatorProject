#include "homewindow.h"
#include "./ui_homewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
