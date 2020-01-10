#pragma once

#include <QWidget>
#include "ui_editgameform.h"
#include "videogame.h"

class EditGameForm : public QWidget
{
	Q_OBJECT

public:
	EditGameForm(QWidget *parent);
	~EditGameForm();

	void SetUp(Videogame* videogame);

signals:
	void goGameInfo(const std::string& title);
	void goLibrary(bool update);

protected slots:
	void bt_deleteClicked();
	void bt_updateClicked();

protected:
	Ui::EditGameForm m_ui;
	Videogame* m_videogame;
};
