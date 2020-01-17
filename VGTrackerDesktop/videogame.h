#pragma once

#include <iostream>

#include "videogamedb.h"


enum SearchOrder {
	Alphabetic = 0,
	ReleaseDate,
	AdditionDate
};

struct SearchParams {
	bool launched;
	bool favourite;
	bool incomingReleases;
	std::string title;
	SearchOrder order;

	SearchParams(bool launched, bool favourite, std::string title, SearchOrder order, bool incomingReleases = false);
};

class Videogame
{
protected:
	std::string m_title,
				m_summary,
				m_releaseDate,
				m_sqlReleaseDate;
					
	bool m_favourite;

	float m_mark;

	VideogameDB m_vgDb;

public:
	Videogame();
	~Videogame();
	
	// Database methods
	bool Save() {
		return m_vgDb.Save(this);
	}
	bool Update() {
		return m_vgDb.Update(this);
	}
	void Read(std::string title) {
		*this = m_vgDb.Read(title);
	}
	void Delete() {
		m_vgDb.Delete(this);
	}

	// Getters & setters
	std::string GetSummary() const {
		return m_summary;
	}
	std::string GetTitle() const {
		return m_title;
	}
	std::string GetReleaseDate() const {
		return m_releaseDate;
	}
	std::string GetSqlReleaseDate() const {
		return m_sqlReleaseDate;
	}
	void SetSummary(std::string& summary) {
		m_summary = summary;
	}
	void SetTitle(std::string& title) {
		m_title = title;
	}
	void SetReleaseDate(std::string& releaseDate) {
		m_releaseDate = releaseDate;
	}
	void SetSqlReleaseDate(std::string& releaseDate) {
		m_sqlReleaseDate = releaseDate;
	}

	// Static functions
	static std::vector<Videogame> AllGames() {
		return VideogameDB::AllGames();
	}

	static std::vector<Videogame> Search(SearchParams filters) {
		return VideogameDB::Search(filters);
	}

};

