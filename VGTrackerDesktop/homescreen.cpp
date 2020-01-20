#include "homescreen.h"
#include "fonts.h"
#include "coverlistitem.h"
#include <QGraphicsDropShadowEffect>

HomeScreen::HomeScreen(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);

	connect(this->m_ui.bt_seeLastAdded, &QPushButton::clicked, this, &HomeScreen::bt_seeAllLastClicked);
	connect(this->m_ui.bt_seeIncomingReleases, &QPushButton::clicked, this, &HomeScreen::bt_seeAllIncomingClicked);
	connect(this->m_ui.bt_seeFavouriteGames, &QPushButton::clicked, this, &HomeScreen::bt_seeAllFavouriteClicked);

	connect(this->m_ui.lw_lastAdded, &QListWidget::itemClicked, this, &HomeScreen::lw_lastSelected);
	connect(this->m_ui.lw_incomingReleases, &QListWidget::itemClicked, this, &HomeScreen::lw_incSelected);
	connect(this->m_ui.lw_favouriteGames, &QListWidget::itemClicked, this, &HomeScreen::lw_favSelected);
	
	AddStyleElements();

	RefreshGamesLists();
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::AddStyleElements()
{
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoLight);
	
	this->m_ui.lb_lastAdded->setFont(nunito);
	this->m_ui.lb_incomingReleases->setFont(nunito);
	this->m_ui.lb_favouriteGames->setFont(nunito);
	this->m_ui.bt_seeLastAdded->setFont(nunito);
	this->m_ui.bt_seeIncomingReleases->setFont(nunito);
	this->m_ui.bt_seeFavouriteGames->setFont(nunito);

	this->m_ui.lb_noGamesLastAdded->setFont(nunito);
	this->m_ui.lb_noGamesIncoming->setFont(nunito);
	this->m_ui.lb_noGamesFav->setFont(nunito);
	
	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_lastAdded->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_incomingReleases->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_favouriteGames->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_noGamesLastAdded->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_noGamesIncoming->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_noGamesFav->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.bt_seeLastAdded->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.bt_seeFavouriteGames->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.bt_seeIncomingReleases->setGraphicsEffect(shadowEffect);


}

void HomeScreen::RefreshGamesLists() {
	std::vector<Videogame> gameList;
	this->m_ui.lw_favouriteGames->clear();
	this->m_ui.lw_incomingReleases->clear();
	this->m_ui.lw_lastAdded->clear();

	constexpr int kMaxItems = 5;
	auto displayedItems = 0;

	SearchParams paramsLastAdded(0, 0, "", SearchOrder::AdditionDate, 0);
	gameList = Videogame::Search(paramsLastAdded);
	displayedItems = min(gameList.size(), kMaxItems);
	if (displayedItems == 0) {
		this->m_ui.lw_lastAdded->setVisible(false);
		this->m_ui.lb_noGamesLastAdded->setVisible(true);
	}
	else {
		std::for_each(begin(gameList), begin(gameList) + displayedItems,
			[&](const Videogame& videogame) {
			std::string itemNameStr = videogame.GetTitle();
			CoverListItem* newRealItem = new CoverListItem(this, itemNameStr);
			QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
			shadowEffect->setBlurRadius(40);
			QColor shadowColor;
			shadowColor.setNamedColor("black");
			shadowEffect->setColor(shadowColor);
			newRealItem->setGraphicsEffect(shadowEffect);
			QListWidgetItem* newItem = new QListWidgetItem();
			newItem->setSizeHint(newRealItem->sizeHint());
			m_ui.lw_lastAdded->addItem(newItem);
			m_ui.lw_lastAdded->setItemWidget(newItem, newRealItem);
		}
		);
		this->m_ui.lb_noGamesLastAdded->setVisible(false);
		this->m_ui.lw_lastAdded->setVisible(true);
	}


	SearchParams paramsIncomingReleases(0, 0, "", SearchOrder::Alphabetic, 1);
	gameList = Videogame::Search(paramsIncomingReleases);
	displayedItems = min(gameList.size(), kMaxItems);
	if (displayedItems == 0) {
		this->m_ui.lw_incomingReleases->setVisible(false);
		this->m_ui.lb_noGamesIncoming->setVisible(true);
	}
	else {
		std::for_each(begin(gameList), begin(gameList) + displayedItems,
			[&](const Videogame& videogame) {
			std::string itemNameStr = videogame.GetTitle();
			CoverListItem* newRealItem = new CoverListItem(this, itemNameStr);
			QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
			shadowEffect->setBlurRadius(40);
			QColor shadowColor;
			shadowColor.setNamedColor("black");
			shadowEffect->setColor(shadowColor);
			newRealItem->setGraphicsEffect(shadowEffect);
			QListWidgetItem* newItem = new QListWidgetItem();
			newItem->setSizeHint(newRealItem->sizeHint());
			m_ui.lw_incomingReleases->addItem(newItem);
			m_ui.lw_incomingReleases->setItemWidget(newItem, newRealItem);
		}
		);
		this->m_ui.lb_noGamesIncoming->setVisible(false);
		this->m_ui.lw_incomingReleases->setVisible(true);
	}

	SearchParams paramsFavourite(0, 1, "", SearchOrder::Alphabetic, 0);
	gameList = Videogame::Search(paramsFavourite);
	displayedItems = min(gameList.size(), kMaxItems);
	if (displayedItems == 0) {
		this->m_ui.lw_favouriteGames->setVisible(false);
		this->m_ui.lb_noGamesFav->setVisible(true);
	}
	else {
		std::for_each(begin(gameList), begin(gameList) + displayedItems,
			[&](const Videogame& videogame) {
			std::string itemNameStr = videogame.GetTitle();
			CoverListItem* newRealItem = new CoverListItem(this, itemNameStr);
			QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
			shadowEffect->setBlurRadius(40);
			QColor shadowColor;
			shadowColor.setNamedColor("black");
			shadowEffect->setColor(shadowColor);
			newRealItem->setGraphicsEffect(shadowEffect);
			QListWidgetItem* newItem = new QListWidgetItem();
			newItem->setSizeHint(newRealItem->sizeHint());
			m_ui.lw_favouriteGames->addItem(newItem);
			m_ui.lw_favouriteGames->setItemWidget(newItem, newRealItem);
		}
		);
		this->m_ui.lb_noGamesFav->setVisible(false);
		this->m_ui.lw_favouriteGames->setVisible(true);
	}
	
}

void HomeScreen::bt_seeAllLastClicked() {
	SearchParams params(0, 0, "", SearchOrder::AdditionDate);
	emit goLibrary(1, params);
}

void HomeScreen::bt_seeAllIncomingClicked() {
	SearchParams params(0, 0, "", SearchOrder::None, 1);
	emit goLibrary(1, params);
}

void HomeScreen::bt_seeAllFavouriteClicked() {
	SearchParams params(0, 1, "", SearchOrder::None);
	emit goLibrary(1, params);
}

void HomeScreen::lw_favSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(this->m_ui.lw_favouriteGames->itemWidget(this->m_ui.lw_favouriteGames->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}
void HomeScreen::lw_lastSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(this->m_ui.lw_lastAdded->itemWidget(this->m_ui.lw_lastAdded->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}
void HomeScreen::lw_incSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(this->m_ui.lw_incomingReleases->itemWidget(this->m_ui.lw_incomingReleases->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}