#pragma once

#include <QListWidget>

class NoteList : public QListWidget
{
	Q_OBJECT


public:
	NoteList(QWidget *parent);
	~NoteList();

	void ResizeToContents() {
		this->setFixedHeight(this->sizeHintForRow(0) * this->count() + 2 * this->frameWidth() + this->spacing() * (this->count()*2));
	}
};
