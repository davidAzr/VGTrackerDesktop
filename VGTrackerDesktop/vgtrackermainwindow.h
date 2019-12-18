#pragma once

#include <QWidget>

#include "ui_VGTrackerMainWindow.h"
#include "library.h"
#include "gameinfo.h"

class VGTrackerMainWindow : public QWidget
{
	Q_OBJECT

public:
	VGTrackerMainWindow(QWidget *parent);
	~VGTrackerMainWindow();
protected slots:
	void ShowGameInfo(const std::string& title);
protected:
	Ui::VGTrackerMain m_ui;

	std::unique_ptr<Library> m_library;
	std::unique_ptr<GameInfo> m_gameInfo;
};
