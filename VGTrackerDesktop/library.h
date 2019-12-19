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
	void lw_gameSelected();

signals:
	void gameSelected(const std::string& title);

protected:
	Ui::wg_library m_ui;
	Videogame m_videogame;
};
