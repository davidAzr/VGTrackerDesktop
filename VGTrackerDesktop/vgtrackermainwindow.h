#pragma once

#include <QWidget>

#include "ui_VGTrackerMainWindow.h"
#include "library.h"
#include "gameinfo.h"
#include "addgameform.h"

class VGTrackerMainWindow : public QWidget
{
	Q_OBJECT

public:
	VGTrackerMainWindow(QWidget *parent);
	~VGTrackerMainWindow();
protected slots:
	void ShowGameInfo(const std::string& title);
	void ShowLibrary(const bool& update = false);
	void ShowAddGame();
protected:
	Ui::VGTrackerMain m_ui;

	std::unique_ptr<Library> m_library;
	std::unique_ptr<GameInfo> m_gameInfo;
	std::unique_ptr<AddGameForm> m_addGameForm;

	void ChangeWindow(QWidget*);
};
