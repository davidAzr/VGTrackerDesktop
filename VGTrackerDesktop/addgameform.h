#pragma once

#include <QWidget>
#include "ui_addgameform.h"

class AddGameForm : public QWidget
{
	Q_OBJECT

public:
	AddGameForm(QWidget *parent);
	~AddGameForm();
protected:
	Ui::AddGameForm m_ui;
};
