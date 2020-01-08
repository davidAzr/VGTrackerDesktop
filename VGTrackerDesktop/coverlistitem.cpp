#include "coverlistitem.h"

#include "fonts.h"

CoverListItem::CoverListItem(QWidget* _parent, const std::string& title)
	: QWidget(_parent)
{
	m_ui.setupUi(this);
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	this->m_ui.lb_name->setFont(nunito);
	std::string coverFile = "designResources/covers/" + title + ".jpg";
	std::replace(std::begin(coverFile), std::end(coverFile), ':', ';');
	QPixmap p(coverFile.c_str()); // load pixmap
	int w = m_ui.lb_coverImage->width();
	int h = m_ui.lb_coverImage->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText(title.c_str());
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));
	
}

CoverListItem::~CoverListItem()
{
}
std::string CoverListItem::GetTitle()
{
	return this->m_ui.lb_name->text().toStdString();
}
