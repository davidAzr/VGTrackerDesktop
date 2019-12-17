#include "videogamedb.h"
#include "videogame.h"

VideogameDB::VideogameDB()
{
	m_conn = mysql_init(0);
	m_conn = mysql_real_connect(m_conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);
}

bool VideogameDB::Save(Videogame * videogame)
{
	if (m_conn) {
		std::string query = "INSERT INTO Videogame VALUES ('" + videogame->GetTitle() + "', '" + videogame->GetSummary() + "', '" + videogame->GetReleaseDate() + "');";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			return true;
		}
	}
	return false;
}

bool VideogameDB::Update(Videogame * videogame)
{
	if (m_conn) {
		std::string query = "UPDATE Videogame SET summary='" + videogame->GetSummary() + "', releaseDate='" + videogame->GetReleaseDate() + " WHERE title='" + videogame->GetTitle() + "';";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			return true;
		}
	}
	return false;
}

Videogame VideogameDB::Read(std::string title) {
	Videogame videogame;
	if (m_conn) {
		std::string query = "SELECT * FROM Videogame WHERE title='" + title + "';";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			MYSQL_RES* res = mysql_store_result(m_conn);
			MYSQL_ROW row = mysql_fetch_row(res);
			videogame.SetTitle(std::string(row[0]));
			videogame.SetSummary(std::string(row[1]));
			videogame.SetReleaseDate(std::string(row[2]));
		}
	}
	return videogame;
}

std::vector<Videogame> VideogameDB::AllGames()
{
	std::vector<Videogame> videogames;

	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);

	if (conn) {
		std::string query = "SELECT * FROM Videogame ;";
		const char* q = query.c_str();
		int qstate = mysql_query(conn, q);
		if (!qstate) {
			
			MYSQL_RES* res = mysql_store_result(conn);
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res)) {
				Videogame videogame;
				videogame.SetTitle(std::string(row[0]));
				videogame.SetSummary(std::string(row[1]));
				videogame.SetReleaseDate(std::string(row[2]));
				videogames.push_back(videogame);
			}
		}
	}
	return videogames;
}
