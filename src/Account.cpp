#include <Account.h>

Account::Account()
    : id {0}, username {""}, password {""}, logged_in {false}
{}

Account::Account(std::string username, std::string password)
    : Account()
{
    login(username, password);
}

void Account::login(std::string username, std::string password)
{
    // Hard-coded authentication, until using a database
    if(username == "admin" && password == "1234")
    {
        logged_in = true;
    }
}

bool Account::is_logged_in()
{
    return logged_in;
}

std::string Account::get_username()
{
    return username;
}

void Account::logout()
{
    logged_in = false;
}