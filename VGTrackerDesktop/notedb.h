#pragma once

#include <iostream>
#include <vector>
#include <mysql.h>

class Note;

class NoteDB
{
protected:
	MYSQL* m_conn;

public:
	NoteDB();
	~NoteDB() {};
	bool Save(const Note* note) const;
	bool Update(const Note* note) const;
	bool Delete(const Note* note) const;
	Note Read(std::string) const;
};