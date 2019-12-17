#include "coverlistitem.h"
#include <QFontDatabase>

CoverListItem::CoverListItem(QWidget* _parent, const std::string& title)
	: QWidget(_parent)
{
	m_ui.setupUi(this);
	std::string coverFile = "designResources/covers/" + title + ".jpg";
	std::replace(std::begin(coverFile), std::end(coverFile), ':', ';');
	QPixmap p(coverFile.c_str()); // load pixmap
	int w = m_ui.lb_coverImage->width();
	int h = m_ui.lb_coverImage->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText(title.c_str());
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
	int id = QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-ExtraBold.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont nunito(family, 10);
	this->m_ui.lb_name->setFont(nunito);
	
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
