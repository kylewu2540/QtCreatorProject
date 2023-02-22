#include "forgotpasswindow.h"
#include "./ui_forgotpasswindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <string>
#include <curl/curl.h>

ForgotPassWindow::ForgotPassWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ForgotPassWindow)
{
    ui->setupUi(this);
}

ForgotPassWindow::~ForgotPassWindow()
{
    delete ui;
}

int ForgotPassWindow::sendEmail(const std::string& recipient, const std::string& subject, const std::string& body)
{
    CURL *curl = curl_easy_init();
    if (curl) {
        // set the email recipient
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, recipient.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // set the email subject and body
        curl_easy_setopt(curl, CURLOPT_SSLCERT, subject.c_str());
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

        // send the email
        CURLcode res = curl_easy_perform(curl);

        // cleanup
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            // email sent successfully
            return 0;
        } else {
            // error sending email
            return 1;
        }
    } else {
        // error initializing libcurl
        return 1;
    }
}

void ForgotPassWindow::on_pushButton_clicked()
{
    std::string recipient = "recipient@example.com";
    std::string subject = "Test email";
    std::string body = "This is a test email sent using libcurl.";
    int result = sendEmail(recipient, subject, body);
    if (result == 0) {
        qDebug() << "Email sent successfully.";
    } else {
        qDebug() << "Error sending email.";
    }

}

