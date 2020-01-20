#include "videogamedb.h"
#include "videogame.h"
#include <string>

VideogameDB::VideogameDB()
{
	m_conn = mysql_init(0);
	m_conn = mysql_real_connect(m_conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);
}

bool VideogameDB::Save(Videogame * videogame)
{
	if (m_conn) {
		std::string summary = videogame->GetSummary();
		char * from, 
			 * to;
		from = new char(summary.length());
		to = new char(summary.length());
		strcpy(from, summary.c_str());
		mysql_real_escape_string(m_conn, to, from, summary.length());
		
		std::string query = "INSERT INTO Videogame VALUES ('" + videogame->GetTitle() + "', '" + to + "', '" + videogame->GetReleaseDate() + "', CURDATE(), 0);";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			return true;
		}
		delete to, from;
	}
	return false;
}

bool VideogameDB::Update(Videogame * videogame)
{
	if (m_conn) {

		std::string summary = videogame->GetSummary();
		char * from,
			*to;
		from = new char(summary.length());
		to = new char(summary.length());
		strcpy(from, summary.c_str());
		mysql_real_escape_string(m_conn, to, from, summary.length());

		std::string query = "UPDATE Videogame SET summary='" + std::string(to) + "', releaseDate='" + videogame->GetSqlReleaseDate() + "', favourite='" + std::to_string(videogame->GetFavourite()) + "' WHERE title='" + videogame->GetTitle() + "';";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			return true;
		}
		delete to, from;
	}
	return false;
}

bool VideogameDB::Delete(Videogame * videogame)
{
	if (m_conn) {
		std::string query = "DELETE FROM Videogame WHERE title='" + videogame->GetTitle() + "';";
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
		std::string query = "SELECT title, summary, releaseDate, DATE_FORMAT(releaseDate, \"%M %D, %Y\"), favourite FROM Videogame WHERE title='" + title + "';";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			MYSQL_RES* res = mysql_store_result(m_conn);
			MYSQL_ROW row = mysql_fetch_row(res);
			if (row[0] != NULL) videogame.SetTitle(std::string(row[0]));
			if (row[1] != NULL) videogame.SetSummary(std::string(row[1]));
			if (row[2] != NULL) videogame.SetSqlReleaseDate(std::string(row[2]));
			if (row[3] != NULL) videogame.SetReleaseDate(std::string(row[3]));
			if (row[4] != NULL) videogame.SetFavourite(atoi(std::string(row[4]).c_str()));
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
		std::string query = "SELECT title, summary, releaseDate, DATE_FORMAT(releaseDate, \"%M %D, %Y\"), favourite FROM Videogame;";
		const char* q = query.c_str();
		int qstate = mysql_query(conn, q);
		if (!qstate) {
			
			MYSQL_RES* res = mysql_store_result(conn);
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res)) {
				Videogame videogame;
				if (row[0] != NULL) videogame.SetTitle(std::string(row[0]));
				if (row[1] != NULL) videogame.SetSummary(std::string(row[1]));
				if (row[2] != NULL) videogame.SetSqlReleaseDate(std::string(row[2]));
				if (row[3] != NULL) videogame.SetReleaseDate(std::string(row[3]));
				if (row[4] != NULL) videogame.SetFavourite(atoi(std::string(row[4]).c_str()));
				videogames.push_back(videogame);
			}
		}
	}
	return videogames;
}

std::vector<Videogame> VideogameDB::Search(SearchParams filters)
{
	std::vector<Videogame> videogames;

	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);


	std::string titleFilter, dateFilter, favouriteFilter, orderFilter;

	titleFilter = " WHERE title LIKE '%" + filters.title + "%' ";
	if (filters.launched) dateFilter = " AND releaseDate > CURDATE() ";
	if (filters.favourite) favouriteFilter = "AND favourite = true"; // To Do
	switch (filters.order) {
		case SearchOrder::Alphabetic:
			orderFilter = " ORDER BY title ";
			break;
		case SearchOrder::AdditionDate:
			orderFilter = " ORDER BY additionDate DESC";
			break;
		case SearchOrder::ReleaseDate:
			orderFilter = " ORDER BY releaseDate DESC ";
			break;
		case SearchOrder::None:
			orderFilter = " ";
			break;
	}

	if (conn) {
		std::string query = "SELECT title, summary, releaseDate, DATE_FORMAT(releaseDate, \"%M %D, %Y\"), favourite FROM Videogame " + titleFilter + dateFilter + favouriteFilter + orderFilter + ";";
		if (filters.incomingReleases) query = "SELECT title, summary, releaseDate, DATE_FORMAT(releaseDate, \"%M %D, %Y\"), favourite FROM Videogame WHERE releaseDate > CURDATE() ORDER BY releaseDate ASC";
		const char* q = query.c_str();
		int qstate = mysql_query(conn, q);
		if (!qstate) {

			MYSQL_RES* res = mysql_store_result(conn);
			MYSQL_ROW row;
			while (row = mysql_fetch_row(res)) {
				Videogame videogame;
				if (row[0] != NULL) videogame.SetTitle(std::string(row[0]));
				if (row[1] != NULL) videogame.SetSummary(std::string(row[1]));
				if (row[2] != NULL) videogame.SetSqlReleaseDate(std::string(row[2]));
				if (row[3] != NULL) videogame.SetReleaseDate(std::string(row[3]));
				if (row[4] != NULL) videogame.SetFavourite(atoi(std::string(row[4]).c_str()));
				videogames.push_back(videogame);
			}
		}
	}
	return videogames;
}