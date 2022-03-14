#include "../include/Account.h"

// Function declarations
void start_system();
void clear_screen();
bool do_login(std::string, std::string);
void display_login_screen(std::string message = "");
void display_options_menu(std::string message = "");

void start_system()
{
    display_login_screen();
}

void clear_screen()
{
    std::system("cls");
}

bool do_login(std::string username, std::string password)
{
    Account account {username, password};
    if(account.is_logged_in())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display_login_screen(std::string message)
{
    std::string username;
    std::string password;

    if(message.empty())
    {
        std::cout << 
        "\n-----------------------------------------------" << "\n" <<
        "- Welcome, to (Clinic name) management system!" << "\n" <<
        "- Address: (the clinic address comes here)" << "\n" <<
        "-----------------------------------------------" << "\n\n";
    }
    else
    {
        clear_screen();
        std::cout << "\nMessage-> ((" << message << "))\n" << std::endl;
    }

    std::cout << 
    "[Login]" << "\n" <<
    "username: ";
    getline(std::cin, username);

    std::cout << 
    "password: ";
    getline(std::cin, password);

    // authentecation
    if(do_login(username, password))
    {
        clear_screen();
        std::string message = {"Welcome, " + username + "!"};
        display_options_menu(message);
    }
    else
    {
        std::string message = {"Wrong username or password. You can try again."};
        display_login_screen(message);
    }
}

void display_options_menu(std::string message)
{
    if(!message.empty())
    {
        std::cout << message << std::endl; 
    }
    
    std::cout << "\nYou can use the following options' titles or numbers:\n" << std::endl;
    std::cout << 
    "1. display doctors" << "\n" <<
    "2. display doctor" << "\n" <<
    "3. add doctor" << "\n" <<
    "4. edit doctor" << "\n" <<
    "5. delete doctor" << "\n\n" <<

    "6. display patients" << "\n" <<
    "7. display patient" << "\n" <<
    "8. add patient" << "\n" <<
    "9. edit patient" << "\n" <<
    "10. delete patient" << "\n\n" <<

    "11. display services" << "\n" <<
    "12. display service" << "\n" <<
    "13. add service" << "\n" <<
    "14. edit service" << "\n" <<
    "15. delete service" << "\n\n" <<

    "16. display appointments" << "\n" <<
    "17. display appointment" << "\n" <<
    "18. add appointment" << "\n" <<
    "19. edit appointment" << "\n" <<
    "20. delete appointment" << "\n\n" <<

    "21. edit account username" << "\n" << 
    "22. edit account password" << "\n\n" <<

    "23. edit system name" << "\n" <<
    "24. edit system address" << "\n\n" <<

    "25. help" << "\n"  <<
    "25. clear" << "\n" <<
    "27. exit" << "\n\n";

    std::string option;
    std::cout << "> ";
    getline(std::cin, option);

    std::cout << "Your option is " << option << std::endl;
}