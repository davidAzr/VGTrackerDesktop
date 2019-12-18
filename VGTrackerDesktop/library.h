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

protected slots:
	void bt_loadWitcherOnClick();
	void bt_loadCyberOnClick();
	void bt_loadMassOnClick();

protected:
	Ui::wg_library m_ui;
	Videogame m_videogame;
	void UpdateGameInfo();
};
