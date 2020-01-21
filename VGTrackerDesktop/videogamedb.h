#pragma once

#include <iostream>
#include <vector>
#include <mysql.h>

class Videogame;
class Note;
struct SearchParams;



class VideogameDB
{
protected:
	MYSQL* m_conn;

public:
	VideogameDB();
	~VideogameDB() {};
	bool Save(Videogame* videogame);
	bool Update(Videogame* videogame);
	bool Delete(Videogame* videogame);
	Videogame Read(std::string title);
	std::vector<Note> AllNotes(std::string title);

	static std::vector<Videogame> AllGames();
	static std::vector<Videogame> Search(SearchParams filters);
};

