#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User(const QString& username, const QString& password);
    User(const QString& full_name, const QString& username, const QString& email, const QString& password, const QString& confirm_password);

    // getters
    QString getFullName() const;
    QString getUsername() const;
    QString getEmail() const;
    QString getPassword() const;
    QString getConfirmPassword() const;

    // setters
    void setFullName(const QString& full_name);
    void setUsername(const QString& username);
    void setEmail(const QString& email);
    void setPassword(const QString& password);
    void setConfirmPassword(const QString& confirm_password);

private:
    QString full_name;
    QString username;
    QString email;
    QString password;
    QString confirm_password;
};

#endif // USER_H
