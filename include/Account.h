#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account 
{
private:
    int id;
    std::string username;
    std::string password;
    bool logged_in;

public:
    Account();
    Account(std::string, std::string);
    void login(std::string, std::string);
    bool is_logged_in();
    std::string get_username();
    void logout();
};

#endif