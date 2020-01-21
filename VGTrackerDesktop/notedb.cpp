#include "notedb.h"
#include "note.h"
#include <string>

NoteDB::NoteDB()
{
	m_conn = mysql_init(0);
	m_conn = mysql_real_connect(m_conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);
}

bool NoteDB::Save(const Note * note) const
{
	if (m_conn) {
		std::string contents = note->GetContents();
		char * from,
			*to;
		from = new char[contents.length()];
		to = new char[contents.length()];
		strcpy(from, contents.c_str());
		mysql_real_escape_string(m_conn, to, from, contents.length());

		std::string query = "INSERT INTO Note (note, date, game) VALUES ('" + std::string(to) + "', CURDATE(), '" + note->GetGameTitle() + "');";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		//Bdelete[] to, from;
		if (!qstate) {
			return true;
		}
	}
	return false;
}

bool NoteDB::Update(const Note * note) const
{
	return false;
}

bool NoteDB::Delete(const Note * note) const
{
	if (m_conn) {
		std::string query = "DELETE FROM Note WHERE id='" + note->GetId() + "';";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			return true;
		}
	}
	return false;
}

Note NoteDB::Read(std::string id) const
{
	Note note;
	if (m_conn) {
		std::string query = "SELECT note, date, DATE_FORMAT(date, \"%M %D, %Y\"), game, id FROM Note WHERE id = " + id + ";";
		const char* q = query.c_str();
		int qstate = mysql_query(m_conn, q);
		if (!qstate) {
			MYSQL_RES* res = mysql_store_result(m_conn);
			MYSQL_ROW row = mysql_fetch_row(res);
			note.SetId(id);
			if (row[0] != NULL) note.SetContents(std::string(row[0]));
			if (row[1] != NULL) note.SetSqlPublishDate(std::string(row[1]));
			if (row[2] != NULL) note.SetPublishDate(std::string(row[2]));
			if (row[3] != NULL) note.SetGame(std::string(row[3]));
		}
	}
	return note;
}


