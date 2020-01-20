#pragma once

#include <QWidget>

#include "videogame.h"
#include "ui_homescreen.h"

class HomeScreen : public QWidget
{
	Q_OBJECT

public:
	HomeScreen(QWidget *parent);
	~HomeScreen();
	void RefreshGamesLists();

signals:
	void goLibrary(const bool& update, SearchParams params);
	void gameSelected(const std::string& title);

protected slots:
	void bt_seeAllLastClicked();
	void bt_seeAllIncomingClicked();
	void bt_seeAllFavouriteClicked();
	void lw_lastSelected();
	void lw_incSelected();
	void lw_favSelected();

protected:
	Ui::HomeScreen m_ui;
};
