#include <iostream>
#include <string>
#include <cctype>
#include <sqlite3.h>
#include <DB.h>

DB::DB()
	: db_handle {nullptr}, data {nullptr}
{
	data = new std::vector<std::vector<std::string>>;
}

bool DB::connect()
{
	std::string db_file = "my_clinic.db";
	// open a connection to the database
	int conn = sqlite3_open(db_file.c_str(), &db_handle);
	// if the database does not exist and the connection is not open
	if(conn != SQLITE_OK)
	{
		std::string msg = "Unable to open a connection to the database.\nError message: ";
		std::cerr << msg << sqlite3_errmsg(db_handle) << std::endl;
		return false;
	}
	
	return true;
}

std::string DB::get_query_key()
{
	std::string query_key;

	for (int i {0}; i < sql_query.size(); i++)
	{
		if (sql_query[i] == ' ')
		{
			break;
		}
		else
		{
			query_key += tolower(sql_query[i]);
		}
	}

	return query_key;
}

void DB::query(std::string sql)
{
	char* errmsg;

	// connect to the database
	if (connect())
	{
		// define all tables
		std::string create_table_account = "CREATE TABLE IF NOT EXISTS account (id INTEGER PRIMARY KEY, username TEXT, password TEXT);";
		std::string create_table_person = "CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, gender TEXT, contact TEXT, address TEXT, note TEXT, type TEXT, speciality TEXT);";
		std::string create_table_service = "CREATE TABLE IF NOT EXISTS service (id INTEGER PRIMARY KEY, name TEXT, cost REAL);";
		std::string create_table_appointment = "CREATE TABLE IF NOT EXISTS appointment (id INTEGER PRIMARY KEY, doctor_id INTEGER, patient_id INTEGER, date TEXT);";
		std::string create_tables_all = create_table_account + create_table_person + create_table_service + create_table_appointment;
		
		// create tables
		int conn = sqlite3_exec(db_handle, create_tables_all.c_str(), nullptr, nullptr, &errmsg);

		if (conn != SQLITE_OK)
		{
			std::string msg = "Unable to create database tables.\nError message: ";
			std::cerr << msg << sqlite3_errmsg(db_handle) << std::endl;
		}
		else
		{
			// store the SQL query
			sql_query = sql;

			// get the SQL query key
			std::string query_key = get_query_key();

			// if key == "select"
			if (query_key == "select")
			{			
				int conn = sqlite3_exec(db_handle, sql_query.c_str(), store_selected_data, data, &errmsg);

				if (conn != SQLITE_OK)
				{
					std::string msg = "Unable to create database tables.\nError message: ";
					std::cerr << msg << sqlite3_errmsg(db_handle) << std::endl;
				}
			}
			// if KEY == "..."
			else
			{
				int conn = sqlite3_exec(db_handle, sql_query.c_str(), nullptr, nullptr, &errmsg);

				if (conn != SQLITE_OK)
				{
					std::string msg = "Unable to execute the query.\nError message: ";
					std::cerr << msg << sqlite3_errmsg(db_handle) << std::endl;
				}
			}
		}
	}
	else
	{
		std::string message = "Unable to connect to the database.\nError message: ";
		std::cerr << message << sqlite3_errmsg(db_handle);
		sqlite3_free(&errmsg);
	}
}

void DB::reset()
{
	(static_cast<std::vector<std::vector<std::string>>*>(data))->erase((static_cast<std::vector<std::vector<std::string>>*>(data))->begin(), (static_cast<std::vector<std::vector<std::string>>*>(data))->end());
}

DB::~DB()
{
	sqlite3_close(db_handle);
	delete data;
}