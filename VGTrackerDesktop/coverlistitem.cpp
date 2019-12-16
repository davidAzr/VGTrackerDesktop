#include "coverlistitem.h"

CoverListItem::CoverListItem()
{
	m_ui.setupUi(this);
	QPixmap p("witcher3cover.jpg"); // load pixmap
	int w = this->width();
	int h = this->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText("The Witcher 3: Wild Hunt");
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
}

CoverListItem::~CoverListItem()
{
}
