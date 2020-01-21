#include "notelistitem.h"
#include "fonts.h"


NoteListItem::NoteListItem(QWidget *parent, Note note)
	: QWidget(parent), m_noteShown(note)
{
	m_ui.setupUi(this);
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(9);
	m_ui.lb_note->setFont(nunito);
	nunito.setPointSize(7);
	m_ui.lb_date->setFont(nunito);

	m_ui.lb_note->setText(QString::fromStdString(note.GetContents()));
	m_ui.lb_date->setText(QString::fromStdString(note.GetPublishDate()));

	connect(m_ui.bt_delete, &QPushButton::clicked, this, [this] { emit deleted(m_noteShown); });
}

NoteListItem::~NoteListItem()
{
}
