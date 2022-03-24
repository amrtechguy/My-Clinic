#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <sqlite3.h>

class DB
{
private:
	std::string db_file;
	sqlite3 *db_handle {nullptr};
	std::vector<std::vector<std::string>> data;

private:
	static void connect();

public:
	static void query(std::string sql);
};

#endif