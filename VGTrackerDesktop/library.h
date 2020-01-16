#pragma once

#include <QWidget>
#include "ui_library.h"
#include "videogame.h"

class Library : public QWidget
{
	Q_OBJECT

public:
	Library(QWidget *parent);
	~Library();

	void RefreshGamesList(std::vector<Videogame> libraryGames);
	void RefreshGamesList();

protected slots:
	void lw_gameSelected();
	void bt_addGameClicked();
	void FiltersUpdated();
signals:
	void gameSelected(const std::string& title);
	void addGame();

protected:
	Ui::wg_library m_ui;
	Videogame m_videogame;
};
