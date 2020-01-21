#pragma once

#include <QWidget>
#include "ui_noteListItem.h"
#include "note.h"

class NoteListItem : public QWidget
{
	Q_OBJECT

public:
	NoteListItem(QWidget *parent, Note note);
	~NoteListItem();

signals: 
	void deleted(const Note& note);

protected:
	Ui::NoteListItem m_ui;
	Note m_noteShown;
};
