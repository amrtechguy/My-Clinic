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

    std::string option;

    std::cout << "\nYou can use the following  shortcuts or their numbers:\n" << std::endl;
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

    do
    {
        std::cout << "> ";
        getline(std::cin, option);

        // handle selected options
        if(option == "1" || option == "display doctors")
        {
            
        }
        else if(option == "2" || option == "display doctor")
        {

        }
        else if(option == "3" || option == "add doctor")
        {

        }
        else if(option == "4" || option == "edit doctor")
        {

        }
        else if(option == "5" || option == "delete doctor")
        {

        }
        else if(option == "6" || option == "display patients")
        {

        }
        else if(option == "7" || option == "display patient")
        {

        }
        else if(option == "8" || option == "add patient")
        {

        }
        else if(option == "9" || option == "edit patient")
        {

        }
        else if(option == "10" || option == "delete patient")
        {

        }
        else if(option == "11" || option == "display services")
        {

        }
        else if(option == "12" || option == "display service")
        {

        }
        else if(option == "13" || option == "add service")
        {

        }
        else if(option == "14" || option == "edit service")
        {

        }
        else if(option == "15" || option == "delete service")
        {

        }
        else if(option == "16" || option == "display appointments")
        {

        }
        else if(option == "17" || option == "display appointment")
        {

        }
        else if(option == "18" || option == "add appointment")
        {

        }
        else if(option == "19" || option == "edit appointment")
        {

        }
        else if(option == "20" || option == "delete appointment")
        {

        }
        else if(option == "21" || option == "edit account username")
        {

        }
        else if(option == "22" || option == "edit account password")
        {

        }
        else if(option == "23" || option == "edit system name")
        {

        }
        else if(option == "24" || option == "edit system address")
        {

        }
        else if(option == "25" || option == "help")
        {
            // display a list of valid options
        }
        else if(option == "26" || option == "clear")
        {
            clear_screen();
        }
        else if(option == "27" || option == "exit")
        {
            std::cout << "\nGoodbye!\n" << std::endl;
        }
        else
        {
            std::cout << "\nInvalid option. Type `help` for a list of valid options.\n" << std::endl;
        }
    }
    while(option != "exit" && option != "27");
}