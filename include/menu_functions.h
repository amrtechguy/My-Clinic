#ifndef MENU_FUNCTIONS
#define MENU_FUNCTIONS

#include <vector>
#include <string>
#include <DB.h>

void print_data(const std::vector<std::vector<std::string>> *data)
{
    if(data->size() <= 1)
    {
        std::cout << "\nMessage-> It's empty.\n" << std::endl;
    }
    else
    {
        std::cout << "\n[Results count: " << (data->size() - 1) << "]\n" << std::endl;
        for (int i {0}; i < data->size(); i++)
        {
            for (int j {0}; j < data->at(i).size(); j++)
            {
                std::cout << data->at(i).at(j) << "\t\t\t";
            }

            std::cout << std::endl;
        }
    }
}

void display_doctors()
{
    DB db;

    // select all doctors from database
    db.query("SELECT * FROM person WHERE type = 'doctor'");

    // handle data
    print_data(db.get_data());
}

void display_doctor()
{
    
}

void add_doctor()
{
    // declare variables
    std::string name, gender, contact, address, note, type = {"doctor"}, speciality;

    std::cout << "\n[Adding a new doctor]\n" << std::endl;

    // get the person info
    std::cout << "Full name: ";
    std::getline(std::cin, name);

    std::cout << "gender (male/female): ";
    std::getline(std::cin, gender);

    std::cout << "contact (phone number): ";
    std::getline(std::cin, contact);

    std::cout << "Address: ";
    std::getline(std::cin, address);

    std::cout << "Note: ";
    std::getline(std::cin, note);

    std::cout << "speciality: ";
    std::getline(std::cin, speciality);

    // add to the databse
    std::string sql_query("INSERT INTO person ('name', 'gender', 'contact', 'address', 'note', 'type', 'speciality') VALUES ('" + name + "','" + gender + "','" + contact + "','" + address + "','" + note +
        "','" + type + "','" + speciality + "')");
    DB db;
    db.query(sql_query);

    // success
    if(db.get_last_insert_rowid())
    {
        std::cout << "\nA new doctor was added successfully!\n" << std::endl;
    }
    else
    {
        std::cout << "Message-> [Unable to add a new doctor to the database. Please, try again later.]" << std::endl;
    }
}

void edit_doctor()
{
    
}

void delete_doctor()
{
    
}

void display_patients()
{

}

void display_patient()
{
    
}

void add_patient()
{
    
}

void edit_patient()
{
    
}

void delete_patient()
{
    
}

void display_services()
{
    DB db;

    // select all doctors from database
    db.query("SELECT * FROM service");

    // handle data
    print_data(db.get_data());
}

void display_service()
{
    
}

void add_service()
{
    // declare variables
    std::string name;
    std::string cost;

    std::cout << "\n[Adding a new service]\n" << std::endl;

    // get the person info
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Cost (0.0): ";
    std::getline(std::cin, cost);

    // add to the databse
    std::string sql_query = "INSERT INTO service ('name', 'cost') VALUES ('" + name + "', '" + cost + "')";
    DB db;
    db.query(sql_query);

    // success
    if (db.get_last_insert_rowid())
    {
        std::cout << "\nA new service was added successfully!\n" << std::endl;
    }
    else
    {
        std::cout << "Message-> [Unable to add a new service to the database. Please, try again later.]" << std::endl;
    }
}

void edit_service()
{
    
}

void delete_service()
{
    
}

void display_appointments()
{

}

void display_appointment()
{
    
}

void add_appointment()
{
    
}

void edit_appointment()
{
    
}

void delete_appointment()
{
    
}

void edit_account_username()
{
    
}

void edit_account_password()
{
    
}

void edit_system_name()
{
    
}

void edit_system_address()
{
    
}

#endif