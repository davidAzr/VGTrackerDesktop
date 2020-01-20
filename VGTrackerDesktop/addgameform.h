#pragma once

#include <QWidget>
#include "ui_addgameform.h"

#include "videogame.h"

class AddGameForm : public QWidget
{
	Q_OBJECT

public:
	AddGameForm(QWidget *parent);
	~AddGameForm();

	void Reset();

signals:
	void goLibrary(bool update, SearchParams params);

protected slots:
	void GetSelectedFile();
	void bt_addClicked();

protected:
	Ui::AddGameForm m_ui;
	std::unique_ptr<Videogame> m_videogame;
};
