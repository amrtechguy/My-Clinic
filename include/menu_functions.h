#ifndef MENU_FUNCTIONS
#define MENU_FUNCTIONS

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <DB.h>
#include <Utility.h>

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

void add_person(std::string person_type)
{
    // declare variables
    std::string name, gender, contact, address, note, type = person_type, speciality;

    std::cout << "\n[Adding a new " + person_type + "]\n" << std::endl;

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

    if(person_type == "doctor")
    {
        std::cout << "speciality: ";
        std::getline(std::cin, speciality);
    }

    // add to the databse
    std::string sql_query("INSERT INTO person (`name`, `gender`, `contact`, `address`, `note`, `type`, `speciality`) VALUES ('" + name + "','" + gender + "','" + contact + "','" + address + "','" + note +
        "','" + type + "','" + speciality + "')");
    DB db;
    db.query(sql_query);

    // success
    if (db.get_last_insert_rowid())
    {
        display_msg("A new " + person_type + " was added successfully!");
    }
    else
    {
        display_msg("Unable to add a new " + person_type + " to the database. Please, try again later.");
    }
}

void display_row(std::string table_name)
{

}

void display_doctors()
{
    DB db;

    // select all doctors from database
    db.query("SELECT * FROM person WHERE `type` = 'doctor'");

    // handle data
    print_data(db.get_data());
}

void display_doctor()
{
    // get the doctor id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do query
    DB db;
    db.query("SELECT * FROM person WHERE `id` = '" + id + "' AND `type` = 'doctor'");
    if(db.get_data()->size() > 1)
    {
        print_data(db.get_data());
    }
    else
    {
        display_msg("There's no doctor with this ID");
    }
}

void add_doctor()
{
    add_person("doctor");
}

void edit_doctor()
{
    
}

void delete_doctor()
{
    // get the id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do a query
    DB db;
    db.query("DELETE FROM person WHERE `id` = '" + id + "' AND `type` = 'doctor'");
    display_msg("Done!");
}

void display_patients()
{
    DB db;

    // select all doctors from database
    db.query("SELECT * FROM person WHERE `type` = 'patient'");

    // handle data
    print_data(db.get_data());
}

void display_patient()
{
    // get the doctor id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do query
    DB db;
    db.query("SELECT * FROM person WHERE `id` = '" + id + "' AND `type` = 'patient'");
    if (db.get_data()->size() > 1)
    {
        print_data(db.get_data());
    }
    else
    {
        display_msg("There's no patient with this ID");
    }
}

void add_patient()
{
    add_person("patient");
}

void edit_patient()
{
    
}

void delete_patient()
{
    // get the id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do a query
    DB db;
    db.query("DELETE FROM person WHERE `id` = '" + id + "' AND `type` = 'patient'");
    display_msg("Done!");
}

void display_services()
{
    DB db;
    db.query("SELECT * FROM service");
    print_data(db.get_data());
}

void display_service()
{
    // get the doctor id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do query
    DB db;
    db.query("SELECT * FROM service WHERE `id` = '" + id + "'");
    if (db.get_data()->size() > 1)
    {
        print_data(db.get_data());
    }
    else
    {
        display_msg("There's no service with this ID");
    }
}

void add_service()
{
    // declare variables
    std::string name, cost;

    std::cout << "\n[Adding a new service]\n" << std::endl;

    // get the person info
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << "Cost (0.0): ";
    std::getline(std::cin, cost);

    // add to the databse
    std::string sql_query = "INSERT INTO service (`name`, `cost`) VALUES ('" + name + "', '" + cost + "')";
    DB db;
    db.query(sql_query);

    // success
    if (db.get_last_insert_rowid())
    {
        display_msg("A new service was added successfully!");
    }
    else
    {
        display_msg("Unable to add a new service to the database. Please, try again later.");
    }
}

void edit_service()
{
    
}

void delete_service()
{
    // get the id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do a query
    DB db;
    db.query("DELETE FROM service WHERE `id` = '" + id + "'");
    display_msg("Done!");
}

void display_appointments()
{
    DB db;
    db.query("SELECT * FROM appointment");
    print_data(db.get_data());
}

void display_appointment()
{
    // get the doctor id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do query
    DB db;
    db.query("SELECT * FROM appointment WHERE `id` = '" + id + "'");
    if (db.get_data()->size() > 1)
    {
        print_data(db.get_data());
    }
    else
    {
        display_msg("There's no appointment with this ID");
    }
}

void add_appointment()
{
    // declare variables
    std::string doctor_id, patient_id, date;

    std::cout << "\n[Adding a new appointment]\n" << std::endl;

    // get the person info
    std::cout << "Docotr ID: ";
    std::getline(std::cin, doctor_id);

    std::cout << "Patient ID: ";
    std::getline(std::cin, patient_id);

    std::cout << "DATE (DD-MM-YYYY): ";
    std::getline(std::cin, date);

    // add to the databse
    std::string sql_query = "INSERT INTO appointment (`doctor_id`, `patient_id`, `date`) VALUES ('" + doctor_id + "', '" + patient_id + "', '" + date + "')";
    DB db;
    db.query(sql_query);

    // success
    if (db.get_last_insert_rowid())
    {
        display_msg("A new appointment was added successfully!");
    }
    else
    {
        display_msg("Unable to add a new appointment to the database. Please, try again later.");
    }
}

void edit_appointment()
{
    
}

void delete_appointment()
{
    // get the id from user
    std::string id;
    std::cout << "\nEnter ID: ";
    std::cin >> id;
    std::cin.ignore();

    // do a query
    DB db;
    db.query("DELETE FROM appointment WHERE `id` = '" + id + "'");
    display_msg("Done!");
}

void edit_account_username()
{
    
}

void edit_account_password()
{
    
}

#endif