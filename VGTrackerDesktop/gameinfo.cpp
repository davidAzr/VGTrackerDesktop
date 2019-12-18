#include "gameinfo.h"

GameInfo::GameInfo(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);
}

GameInfo::~GameInfo()
{
}

void GameInfo::LoadGame(const std::string & title)
{
	this->m_gameShown.Read(title);
	UpdateGameInfo();
}

void GameInfo::UpdateGameInfo()
{
	m_ui.lb_title->setText(QString::fromStdString(m_gameShown.GetTitle()));
	m_ui.lb_summary->setText(QString::fromStdString(m_gameShown.GetSummary()));
	m_ui.lb_releasedate->setText(QString::fromStdString(m_gameShown.GetReleaseDate()));

	std::string coverFile = "designResources/covers/" + m_gameShown.GetTitle() + ".jpg";
	std::replace(std::begin(coverFile), std::end(coverFile), ':', ';');
	QPixmap p(coverFile.c_str()); // load pixmap
	m_ui.lb_cover->setPixmap(p);
}
