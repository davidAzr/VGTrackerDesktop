#pragma once

#include <QWidget>

#include "ui_VGTrackerMainWindow.h"
#include "library.h"
#include "gameinfo.h"
#include "addgameform.h"
#include "editgameform.h"
#include "homescreen.h"

class VGTrackerMainWindow : public QWidget
{
	Q_OBJECT

public:
	VGTrackerMainWindow(QWidget *parent);
	~VGTrackerMainWindow();
protected slots:
	void ShowGameInfo(const std::string& title);
	void ShowLibrary(const bool& update = false);
	void ShowHome(const bool& update = false);
	void ShowAddGame();
	void ShowEditGame(Videogame* videogame);
	void UpdateStyle();
protected:
	Ui::VGTrackerMain m_ui;

	std::unique_ptr<Library> m_library;
	std::unique_ptr<GameInfo> m_gameInfo;
	std::unique_ptr<AddGameForm> m_addGameForm;
	std::unique_ptr<EditGameForm> m_editGameForm;
	std::unique_ptr<HomeScreen> m_homeScreen;

	void ChangeWindow(QWidget*);
};
