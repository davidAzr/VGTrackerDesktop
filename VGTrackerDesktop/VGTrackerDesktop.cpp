#include "VGTrackerDesktop.h"

VGTrackerDesktop::VGTrackerDesktop(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	connect(this->m_ui.bt_loadWitcher, &QPushButton::clicked, this, &VGTrackerDesktop::bt_loadWitcherOnClick);
	connect(this->m_ui.bt_loadCyber, &QPushButton::clicked, this, &VGTrackerDesktop::bt_loadCyberOnClick);
	connect(this->m_ui.bt_loadMass, &QPushButton::clicked, this, &VGTrackerDesktop::bt_loadMassOnClick);
}

void VGTrackerDesktop::bt_loadWitcherOnClick()
{
	m_videogame.Read("The Witcher 3: Wild Hunt");
	UpdateGameInfo();
}

void VGTrackerDesktop::bt_loadCyberOnClick()
{
	m_videogame.Read("Cyberpunk 2077");
	UpdateGameInfo();
}

void VGTrackerDesktop::bt_loadMassOnClick()
{
	m_videogame.Read("Mass Effect");
	UpdateGameInfo();
}

void VGTrackerDesktop::UpdateGameInfo()
{
	m_ui.lb_title->setText(QString::fromStdString(m_videogame.GetTitle()));
	m_ui.lb_summary->setText(QString::fromStdString(m_videogame.GetSummary()));
	m_ui.lb_releaseDate->setText(QString::fromStdString(m_videogame.GetReleaseDate()));
}

