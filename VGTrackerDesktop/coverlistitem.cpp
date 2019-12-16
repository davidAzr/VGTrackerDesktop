#include "coverlistitem.h"

CoverListItem::CoverListItem()
{
	m_ui.setupUi(this);
	QPixmap p("witcher3cover.jpg"); // load pixmap
	int w = m_ui.lb_coverImage->width();
	int h = m_ui.lb_coverImage->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText("The Witcher 3: Wild Hunt");
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
}

CoverListItem::~CoverListItem()
{
}
/*
void CoverListItem::resizeEvent(QResizeEvent * event)
{
	QPixmap p("witcher3cover.jpg"); // load pixmap
	int w = m_ui.lb_coverImage->width();
	int h = m_ui.lb_coverImage->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText("The Witcher 3: Wild Hunt");
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
}
*/
