#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Account.h>
#include <menu_functions.h>

// Function declarations
void start_system();
void clear_screen();
bool do_login(std::string, std::string);
void display_login_screen(std::string message = "");
void display_options_menu(std::string message = "");
void handle_menu_options();

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
        "- Welcome, to My Clinic management system!" << "\n" <<
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
        handle_menu_options();
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

    std::cout << "\nYou can use the following  options by names or numbers:\n" << std::endl;
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

    "21. edit account password" << "\n\n" <<

    "22. help" << "\n"  <<
    "23. clear" << "\n" <<
    "24. exit" << "\n\n";

}

void handle_menu_options()
{
    std::string option;
    
    do
    {
        std::cout << "> ";
        getline(std::cin, option);

        // handle selected options
        if(option == "1" || option == "display doctors")
        {
            display_doctors();
        }
        else if(option == "2" || option == "display doctor")
        {
            display_doctor();
        }
        else if(option == "3" || option == "add doctor")
        {
            add_doctor();
        }
        else if(option == "4" || option == "edit doctor")
        {
            edit_doctor();
        }
        else if(option == "5" || option == "delete doctor")
        {
            delete_doctor();
        }
        else if(option == "6" || option == "display patients")
        {
            display_patients();
        }
        else if(option == "7" || option == "display patient")
        {
            display_patient();
        }
        else if(option == "8" || option == "add patient")
        {
            add_patient();
        }
        else if(option == "9" || option == "edit patient")
        {
            edit_patient();
        }
        else if(option == "10" || option == "delete patient")
        {
            delete_patient();
        }
        else if(option == "11" || option == "display services")
        {
            display_services();
        }
        else if(option == "12" || option == "display service")
        {
            display_service();
        }
        else if(option == "13" || option == "add service")
        {
            add_service();
        }
        else if(option == "14" || option == "edit service")
        {
            edit_service();
        }
        else if(option == "15" || option == "delete service")
        {
            delete_service();
        }
        else if(option == "16" || option == "display appointments")
        {
            display_appointments();
        }
        else if(option == "17" || option == "display appointment")
        {
            display_appointment();
        }
        else if(option == "18" || option == "add appointment")
        {
            add_appointment();
        }
        else if(option == "19" || option == "edit appointment")
        {
            edit_appointment();
        }
        else if(option == "20" || option == "delete appointment")
        {
            delete_appointment();
        }
        else if(option == "21" || option == "edit account password")
        {
            edit_account_password();
        }
        else if(option == "22" || option == "help")
        {
            display_options_menu();
        }
        else if(option == "23" || option == "clear")
        {
            clear_screen();
        }
        else if(option == "24" || option == "exit")
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

#endif