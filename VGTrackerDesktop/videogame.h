#pragma once

#include <iostream>

#include "videogamedb.h"

class Videogame
{
protected:
	std::string m_title,
				m_summary,
				m_releaseDate;
					
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
	bool Read(std::string title) {
		*this = m_vgDb.Read(title);
	}

	// Getters & setters
	std::string GetSummary() {
		return m_summary;
	}
	std::string GetTitle() {
		return m_title;
	}
	std::string GetReleaseDate() {
		return m_releaseDate;
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

};

