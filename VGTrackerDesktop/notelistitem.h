#pragma once

#include <QWidget>
#include "ui_noteListItem.h"

class NoteListItem : public QWidget
{
	Q_OBJECT

public:
	NoteListItem(QWidget *parent);
	~NoteListItem();

protected:
	Ui::NoteListItem m_ui;
};
