#include "vgtrackermainwindow.h"

VGTrackerMainWindow::VGTrackerMainWindow(QWidget *parent)
	: QWidget(parent)
{
	
	this->m_ui.setupUi(this);
	
	m_library = std::make_unique<Library>(this);
	m_gameInfo = std::make_unique<GameInfo>(this);
	m_gameInfo->setVisible(false);

	this->m_ui.lo_widgetholder->addWidget(m_library.get());

	connect(m_library.get(), &Library::gameSelected, this, &VGTrackerMainWindow::ShowGameInfo);
}

VGTrackerMainWindow::~VGTrackerMainWindow()
{
}

void VGTrackerMainWindow::ShowGameInfo(const std::string & title)
{
	this->m_gameInfo->LoadGame(title);


	this->m_ui.lo_widgetholder->replaceWidget(m_library.get(), m_gameInfo.get());
	m_library->setVisible(false);
	m_gameInfo->setVisible(true);
}
