#pragma once

#include <QWidget>

#include "ui_gameinfo.h"

#include "videogame.h"

class GameInfo : public QWidget
{
	Q_OBJECT

public:
	GameInfo(QWidget *parent);
	~GameInfo();
	void LoadGame(const std::string& title);

protected:
	Ui::GameInfo m_ui;
	Videogame m_gameShown;

	void UpdateGameInfo();
};
