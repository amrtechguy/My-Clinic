#ifndef DB_H
#define DB_H

#include <typeinfo>
#include <string>
#include <vector>
#include <sqlite3.h>

class DB
{
private:
	std::string db_file;
	sqlite3 *db_handle;
	std::string sql_query;
	void *data;
	int last_insert_rowid;

private:
	bool connect();
	std::string get_query_key();
	friend int store_selected_data(void* data, int argc, char** argv, char** azColName);

public:
	DB();
	void query(std::string sql);
	auto get_data()
	{
		return (static_cast<std::vector<std::vector<std::string>>*>(data));
	}
	int get_last_insert_rowid();
	void reset();
	~DB();
};

static int store_selected_data(void* data, int argc, char** argv, char** azColName)
{
	std::vector<std::string> single_row;

	// store the column names
	if ((static_cast<std::vector<std::vector<std::string>>*>(data))->size() == 0)
	{
		for (int i{0}; i < argc; i++)
		{
			single_row.push_back(azColName[i]);
		}

		(static_cast<std::vector<std::vector<std::string>>*>(data))->push_back(single_row);
		single_row.erase(single_row.begin(), single_row.end());
	}
	else
	{
		// store the rows
		for (int i{0}; i < argc; i++)
		{
			single_row.push_back(argv[i]);
		}

		(static_cast<std::vector<std::vector<std::string>>*>(data))->push_back(single_row);
		single_row.erase(single_row.begin(), single_row.end());
	}

	return 0;
}

#endif