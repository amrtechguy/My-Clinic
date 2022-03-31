#include <Account.h>
#include <DB.h>

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
    std::string sql_query = "SELECT * FROM account WHERE `username` = '" + username + "' AND `password` = '" + password + "'";

    DB db;
    db.query(sql_query);
    if(db.get_data()->size() > 1)
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