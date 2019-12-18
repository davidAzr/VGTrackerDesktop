#include "library.h"
#include "coverlistitem.h"

#include <QFontDatabase>

Library::Library(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);
	connect(this->m_ui.bt_loadWitcher, &QPushButton::clicked, this, &Library::bt_loadWitcherOnClick);
	connect(this->m_ui.bt_loadCyber, &QPushButton::clicked, this, &Library::bt_loadCyberOnClick);
	connect(this->m_ui.bt_loadMass, &QPushButton::clicked, this, &Library::bt_loadMassOnClick);

	connect(this->m_ui.lw_library, &QListWidget::itemClicked, this, &Library::lw_gameSelected);

	int id = QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Regular.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);
	QFont nunito(family);
	this->setFont(nunito);
	this->m_ui.stackedWidget->setCurrentIndex(0);

	std::vector<Videogame> libraryGames = Videogame::AllGames();

	std::for_each(begin(libraryGames), end(libraryGames),
		[&](const Videogame& videogame) {
		std::string itemNameStr = videogame.GetTitle();
		CoverListItem* newRealItem = new CoverListItem(this, itemNameStr);
		QListWidgetItem* newItem = new QListWidgetItem();
		newItem->setSizeHint(newRealItem->sizeHint());
		m_ui.lw_library->addItem(newItem);
		m_ui.lw_library->setItemWidget(newItem, newRealItem);
	}
	);
	/*
	for (auto i = 0; i < 50; ++i)
	{
		std::string itemNameStr = "prueba de juego" + std::to_string(i);
		CoverListItem* newRealItem = new CoverListItem(this);
		QListWidgetItem* newItem = new QListWidgetItem();
		newItem->setSizeHint(newRealItem->sizeHint());
		m_ui.lw_library->addItem(newItem);
		m_ui.lw_library->setItemWidget(newItem, newRealItem);
	}
	*/
	this->setFont(nunito);
}

void Library::bt_loadWitcherOnClick()
{
	m_videogame.Read("The Witcher 3: Wild Hunt");
	UpdateGameInfo();
}

void Library::bt_loadCyberOnClick()
{
	m_videogame.Read("Cyberpunk 2077");
	UpdateGameInfo();
}

void Library::bt_loadMassOnClick()
{
	m_videogame.Read("Mass Effect");
	UpdateGameInfo();
}

void Library::lw_gameSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(this->m_ui.lw_library->itemWidget(this->m_ui.lw_library->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}

void Library::UpdateGameInfo()
{
	m_ui.lb_title->setText(QString::fromStdString(m_videogame.GetTitle()));
	m_ui.lb_summary->setText(QString::fromStdString(m_videogame.GetSummary()));
	m_ui.lb_releaseDate->setText(QString::fromStdString(m_videogame.GetReleaseDate()));
}

Library::~Library()
{
}
