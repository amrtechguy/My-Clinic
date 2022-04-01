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
                std::cout << data->at(i).at(j) << "\t";
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

void edit_person(std::string person_type)
{
    // Get the element ID from the user
    std::cout << "\n[Editing a " + person_type + "]\n";
    std::string person_id{ 0 };
    std::cout << "Enter " + person_type + " ID: ";
    std::cin >> person_id;
    std::cin.ignore();

    // Get the element data from database
    DB db;
    db.query("SELECT * FROM person WHERE `id` = '" + person_id + "' AND `type` = '" + person_type + "'");

    if (db.get_data()->size() > 1)
    {
        auto row = db.get_data()->at(1);
        std::string id{ row.at(0) }, name{ row.at(1) }, gender{ row.at(2) }, contact{ row.at(3) }, address{ row.at(4) }, note{ row.at(5) }, type{ row.at(6) }, speciality{ row.at(7) };
        std::cout << "\n[Leave it blank if you want to keep the current value]\n" << std::endl;

        std::string new_name, new_gender, new_contact, new_address, new_note, new_speciality;

        std::cout << "Name [" + name + "]: ";
        std::getline(std::cin, new_name);
        if (new_name == "")
        {
            new_name = name;
        }

        std::cout << "Gender [" + gender + "]: ";
        std::getline(std::cin, new_gender);
        if (new_gender == "")
        {
            new_gender = gender;
        }

        std::cout << "Contact [" + contact + "]: ";
        std::getline(std::cin, new_contact);
        if (new_contact == "")
        {
            new_contact = contact;
        }

        std::cout << "Address [" + address + "]: ";
        std::getline(std::cin, new_address);
        if (new_address == "")
        {
            new_address = address;
        }

        std::cout << "Note [" + note + "]: ";
        std::getline(std::cin, new_note);
        if (new_note == "")
        {
            new_note = note;
        }

        if (person_type == "doctor")
        {
            std::cout << "Speciality [" + speciality + "]: ";
            std::getline(std::cin, new_speciality);
            if (new_speciality == "")
            {
                new_speciality = speciality;
            }
        }

        // Update the row
        std::string sql_query = "UPDATE person SET `name` = '" + new_name + "', `gender` = '" + new_gender + "', `contact` = '" + new_contact + "', `address` = '" + new_address + "', `note` = '" + new_note + "', `speciality` = '" + new_speciality + "' WHERE `id` = '" + id + "'";
        db.query(sql_query);

        display_msg("Done!");
    }
    else
    {
        display_msg("There's no " + person_type + " by this ID.");
    }
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
    edit_person("doctor");
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
    edit_person("patient");
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
    // Get the element ID from the user
    std::cout << "\n[Editing a service]\n";
    std::string service_id {0};
    std::cout << "Enter service ID: ";
    std::cin >> service_id;
    std::cin.ignore();

    // Get the element data from database
    DB db;
    db.query("SELECT * FROM service WHERE `id` = '" + service_id + "'");
    
    if(db.get_data()->size() > 1)
    {
        auto service = db.get_data()->at(1);
        std::string id {service.at(0)}, name {service.at(1)}, cost {service.at(2)};
        std::cout << "\n[Leave it blank if you want to keep the current value]\n" << std::endl;

        std::string new_name, new_cost;

        std::cout << "Name [" + name + "]: ";
        std::getline(std::cin, new_name);
        if(new_name == "")
        {
            new_name = name;
        }

        std::cout << "Cost [" + cost + "]: ";
        std::getline(std::cin, new_cost);
        if (new_cost == "")
        {
            new_cost = cost;
        }

        // Update the row
        std::string sql_query = "UPDATE service SET `name` = '" + new_name + "', `cost` = '" + new_cost + "'";
        db.query(sql_query);

        display_msg("Done!");
    }
    else
    {
        display_msg("There's no service by this ID.");
    }
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
    // Get the element ID from the user
    std::cout << "\n[Editing an appointment]\n";
    std::string appointment_id {0};
    std::cout << "Enter appointment ID: ";
    std::cin >> appointment_id;
    std::cin.ignore();

    // Get the element data from database
    DB db;
    db.query("SELECT * FROM appointment WHERE `id` = '" + appointment_id + "'");

    if (db.get_data()->size() > 1)
    {
        auto row = db.get_data()->at(1);
        std::string id{ row.at(0) }, doctor_id{ row.at(1) }, patient_id{ row.at(2) }, date{ row.at(3) };
        std::cout << "\n[Leave it blank if you want to keep the current value]\n" << std::endl;

        std::string new_doctor_id, new_patient_id, new_date;

        std::cout << "Doctor [" + doctor_id + "]: ";
        std::getline(std::cin, new_doctor_id);
        if (new_doctor_id == "")
        {
            new_doctor_id = doctor_id;
        }

        std::cout << "Patient [" + patient_id + "]: ";
        std::getline(std::cin, new_patient_id);
        if (new_patient_id == "")
        {
            new_patient_id = patient_id;
        }

        std::cout << "Date [" + date + "]: ";
        std::getline(std::cin, new_date);
        if (new_date == "")
        {
            new_date = date;
        }

        // Update the row
        std::string sql_query = "UPDATE appointment SET `doctor_id` = '" + new_doctor_id + "', `patient_id` = '" + new_patient_id + "', `date` = '" + new_date + "'";
        db.query(sql_query);

        display_msg("Done!");
    }
    else
    {
        display_msg("There's no appointment by this ID.");
    }
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

void edit_account_password()
{
    std::string new_password;
    std::cout << "\n[Changing password]\n" << std::endl;
    std::cout << "Enter a new password: ";
    std::getline(std::cin, new_password);
    
    DB db;
    std::string sql_query = "UPDATE account SET `password` = '" + new_password + "' WHERE `username` = 'admin'";
    db.query(sql_query);
    display_msg("Done!");
}

#endif