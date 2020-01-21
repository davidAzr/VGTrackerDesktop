#include "coverlistitem.h"
#include "auxiliary.h"
#include "fonts.h"

CoverListItem::CoverListItem(QWidget* _parent, const std::string& title)
	: QWidget(_parent)
{
	m_ui.setupUi(this);
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	m_ui.lb_name->setFont(nunito);
	std::string transformedTitle = TransformTitleToFilename(title);
	std::string coverFile = "designResources/covers/" + transformedTitle + ".jpg";
	QPixmap p(coverFile.c_str()); // load pixmap

	int pixmapWog = p.width();
	auto maxH = m_ui.lb_coverImage->maximumHeight();
	auto scaledPixmap = p.scaledToHeight(maxH, Qt::SmoothTransformation);
	int pixmapWsc = scaledPixmap.width();
	m_ui.lb_coverImage->setMaximumWidth(pixmapWsc);
	m_ui.lb_coverImage->setPixmap(scaledPixmap);

	m_ui.lb_name->setText(title.c_str());
	
}

CoverListItem::~CoverListItem()
{
}
std::string CoverListItem::GetTitle()
{
	return m_ui.lb_name->text().toStdString();
}

