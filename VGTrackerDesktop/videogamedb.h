#pragma once

#include <iostream>
#include <vector>
#include <mysql.h>

class Videogame;

class VideogameDB
{
	//MYSQL* conn;
	//MYSQL_ROW row;
	//MYSQL_RES* res;
	//conn = mysql_init(0);

	//conn = mysql_real_connect(conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);

	//if (conn) {
	//	std::string query = "SELECT * FROM test";
	//	const char* q = query.c_str();
	//	int qstate = mysql_query(conn, q);
	//	if (!qstate) {
	//		res = mysql_store_result(conn);
	//		while (row = mysql_fetch_row(res)) {
	//			printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
	//		}
	//	}
	//}
protected:
	MYSQL* m_conn;

public:
	VideogameDB();
	~VideogameDB() {};
	bool Save(Videogame* videogame);
	bool Update(Videogame* videogame);
	bool Delete(Videogame* videogame);
	Videogame Read(std::string title);

	static std::vector<Videogame> AllGames();
};

