#include "user.h"

// Constructor with only username and password
User::User(const QString& username, const QString& password) :
    full_name(""), username(username), email(""), password(password), confirm_password("")
{
}

// Constructor with all attributes
User::User(const QString& full_name, const QString& username, const QString& email, const QString& password, const QString& confirm_password) :
    full_name(full_name), username(username), email(email), password(password), confirm_password(confirm_password)
{
}

// Getters
QString User::getFullName() const
{
    return this->full_name;
}

QString User::getUsername() const
{
    return this->username;
}

QString User::getEmail() const
{
    return this->email;
}

QString User::getPassword() const
{
    return this->password;
}

QString User::getConfirmPassword() const
{
    return this->confirm_password;
}

// Setters
void User::setFullName(const QString& full_name)
{
    this->full_name = full_name;
}

void User::setUsername(const QString& username)
{
    this->username = username;
}

void User::setEmail(const QString& email)
{
    this->email = email;
}

void User::setPassword(const QString& password)
{
    this->password = password;
}

void User::setConfirmPassword(const QString& confirm_password)
{
    this->confirm_password = confirm_password;
}

