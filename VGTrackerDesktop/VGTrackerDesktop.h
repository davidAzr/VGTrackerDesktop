#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VGTrackerDesktop.h"

#include "videogame.h"

class VGTrackerDesktop : public QMainWindow
{
	Q_OBJECT

public:
	VGTrackerDesktop(QWidget *parent = Q_NULLPTR);

protected slots:
	void bt_loadWitcherOnClick();
	void bt_loadCyberOnClick();
	void bt_loadMassOnClick();

private:
	Videogame m_videogame;
	Ui::VGTrackerDesktopClass m_ui;

	void UpdateGameInfo();
};
