#include "coverlistitem.h"
#include "auxiliary.h"
#include "fonts.h"

CoverListItem::CoverListItem(QWidget* _parent, const std::string& title)
	: QWidget(_parent)
{
	m_ui.setupUi(this);
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	this->m_ui.lb_name->setFont(nunito);
	std::string transformedTitle = TransformTitleToFilename(title);
	std::string coverFile = "designResources/covers/" + transformedTitle + ".jpg";
	QPixmap p(coverFile.c_str()); // load pixmap
	/*int w = m_ui.lb_coverImage->width();
	int h = m_ui.lb_coverImage->height();
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_name->setText(title.c_str());
	m_ui.lb_coverImage->setPixmap(p.scaled(w, h, Qt::KeepAspectRatio));*/
	int pixmapWog = p.width();
	auto maxH = this->m_ui.lb_coverImage->maximumHeight();
	auto scaledPixmap = p.scaledToHeight(maxH);
	int pixmapWsc = scaledPixmap.width();
	/*
	if (pixmapWsc > m_ui.lb_coverImage->maximumWidth()) {
		auto maxW = this->m_ui.lb_coverImage->maximumWidth();
		scaledPixmap = p.scaledToWidth(maxW);
		int pixmapHsc = scaledPixmap.height();
		m_ui.lb_coverImage->setMaximumHeight(pixmapHsc);
		m_ui.lb_coverImage->setPixmap(scaledPixmap);
	}
	else {
	*/	
		m_ui.lb_coverImage->setMaximumWidth(pixmapWsc);
		m_ui.lb_coverImage->setPixmap(scaledPixmap);
	//}
	m_ui.lb_name->setText(title.c_str());
	
}

CoverListItem::~CoverListItem()
{
}
std::string CoverListItem::GetTitle()
{
	return this->m_ui.lb_name->text().toStdString();
}

