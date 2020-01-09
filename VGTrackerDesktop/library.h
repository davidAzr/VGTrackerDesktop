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

	void RefreshGamesList();

protected slots:
	void lw_gameSelected();
	void bt_addGameClicked();

signals:
	void gameSelected(const std::string& title);
	void addGame();

protected:
	Ui::wg_library m_ui;
	Videogame m_videogame;
};
