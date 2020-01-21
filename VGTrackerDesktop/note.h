#pragma once

#include <iostream>
#include "notedb.h"

class Note
{
protected:
	std::string m_contents,
		m_sqlPublishDate,
		m_publishDate,
		m_gameTitle,
		m_id;

	NoteDB m_noteDb;

public:

	// Getters and Setters;
	std::string GetId() const {
		return m_id;
	}

	std::string GetContents() const {
		return m_contents;
	}

	std::string GetPublishDate() const {
		return m_publishDate;
	}

	std::string GetGameTitle() const {
		return m_gameTitle;
	}

	void SetId(std::string id) {
		m_id = id;
	}

	void SetContents(const std::string& contents) {
		m_contents = contents;
	}

	void SetPublishDate(const std::string& publishDate) {
		m_publishDate = publishDate;
	}

	void SetSqlPublishDate(const std::string& sqlPublishDate) {
		m_sqlPublishDate = sqlPublishDate;
	}

	void SetGame(const std::string& gameTitle) {
		m_gameTitle = gameTitle;
	}

	// Database methods
	bool Save() const {
		return m_noteDb.Save(this);
	}
	bool Update() const {
		return m_noteDb.Update(this);
	}
	void Read(std::string id) {
		*this = m_noteDb.Read(id);
	}
	void Delete() const {
		m_noteDb.Delete(this);
	}

};

