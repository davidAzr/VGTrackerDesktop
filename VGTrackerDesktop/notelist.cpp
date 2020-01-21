#include "notelist.h"

NoteList::NoteList(QWidget *parent)
	: QListWidget(parent)
{
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

NoteList::~NoteList()
{
}
