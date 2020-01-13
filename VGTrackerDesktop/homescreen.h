#pragma once

#include <QWidget>

#include "ui_homescreen.h"

class HomeScreen : public QWidget
{
	Q_OBJECT

public:
	HomeScreen(QWidget *parent);
	~HomeScreen();
	void RefreshGamesLists();

protected:
	Ui::HomeScreen m_ui;
};
