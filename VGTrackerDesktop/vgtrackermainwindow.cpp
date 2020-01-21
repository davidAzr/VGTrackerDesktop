#include "vgtrackermainwindow.h"
#include <QFile>

VGTrackerMainWindow::VGTrackerMainWindow(QWidget *parent)
	: QWidget(parent)
{
	
	m_ui.setupUi(this);
	
	//Check wether to keep creating all widgets on initialization
	//or on demand
	m_homeScreen = std::make_unique<HomeScreen>(this);
	m_library = std::make_unique<Library>(this);
	m_gameInfo = std::make_unique<GameInfo>(this);
	m_addGameForm = std::make_unique<AddGameForm>(this);
	m_editGameForm = std::make_unique<EditGameForm>(this);
	m_gameInfo->setVisible(false);
	m_addGameForm->setVisible(false);
	m_editGameForm->setVisible(false);
	m_library->setVisible(false);

	m_ui.lo_widgetholder->addWidget(m_homeScreen.get());

	connect(m_library.get(), &Library::gameSelected, this, &VGTrackerMainWindow::ShowGameInfo);
	connect(m_library.get(), &Library::addGame, this, &VGTrackerMainWindow::ShowAddGame);
	connect(m_addGameForm.get(), &AddGameForm::goLibrary, this, &VGTrackerMainWindow::ShowLibrary);
	connect(m_gameInfo.get(), &GameInfo::goEdit, this, &VGTrackerMainWindow::ShowEditGame);
	connect(m_editGameForm.get(), &EditGameForm::goLibrary, this, &VGTrackerMainWindow::ShowLibrary);
	connect(m_editGameForm.get(), &EditGameForm::goGameInfo, this, &VGTrackerMainWindow::ShowGameInfo);
	connect(m_homeScreen.get(), &HomeScreen::goLibrary, this, &VGTrackerMainWindow::ShowLibrary);
	connect(m_homeScreen.get(), &HomeScreen::gameSelected, this, &VGTrackerMainWindow::ShowGameInfo);

	connect(m_ui.bt_goHome, &QPushButton::clicked, this, &VGTrackerMainWindow::ShowHome);
	connect(m_ui.bt_goLibrary, &QPushButton::clicked, this, [&] {
		SearchParams params;
		this->ShowLibrary(0, params);
	}
	
	);
	connect(m_ui.bt_restyle, &QPushButton::clicked, this, &VGTrackerMainWindow::UpdateStyle);

}

VGTrackerMainWindow::~VGTrackerMainWindow()
{
}

void VGTrackerMainWindow::ShowLibrary(const bool& update, SearchParams params)
{
	if (update) {
		m_library->FiltersUpdated(params);
	}
	ChangeWindow(m_library.get());
}

void VGTrackerMainWindow::ShowHome()
{
	m_homeScreen->RefreshGamesLists();
	ChangeWindow(m_homeScreen.get());
}

void VGTrackerMainWindow::ShowAddGame()
{
	m_addGameForm->Reset();
	ChangeWindow(m_addGameForm.get());
}

void VGTrackerMainWindow::ShowEditGame(Videogame* videogame)
{
	m_editGameForm->SetUp(videogame);
	ChangeWindow(m_editGameForm.get());
}

void VGTrackerMainWindow::ChangeWindow(QWidget * windowToShow)
{
	auto previousWindow = m_ui.lo_widgetholder->itemAtPosition(0, 0)->widget();
	if (previousWindow != windowToShow) {
		previousWindow->setVisible(false);
		m_ui.lo_widgetholder->replaceWidget(previousWindow, windowToShow);
		windowToShow->setVisible(true);
	}
}

void VGTrackerMainWindow::ShowGameInfo(const std::string & title)
{
	m_gameInfo->LoadGame(title);
	ChangeWindow(m_gameInfo.get());
	m_gameInfo->setVisible(true);
}

void VGTrackerMainWindow::UpdateStyle() {

	auto a = dynamic_cast<QApplication*> (QApplication::instance());
	
	QString fileName = "designResources/style.css";

	// Read in the stylesheet
	QFile stylesheet(fileName);
	stylesheet.open(QFile::ReadOnly);
	QString css = QString(stylesheet.readAll());
	stylesheet.close();

	// Apply the stylesheet
	a->setStyleSheet(css);
}
