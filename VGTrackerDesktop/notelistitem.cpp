#include "notelistitem.h"
#include "fonts.h"

NoteListItem::NoteListItem(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(9);
	m_ui.lb_note->setFont(nunito);
	nunito.setPointSize(7);
	m_ui.lb_date->setFont(nunito);
}

NoteListItem::~NoteListItem()
{
}
