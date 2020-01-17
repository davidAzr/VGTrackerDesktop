#include "homescreen.h"
#include "fonts.h"
#include "videogame.h"
#include "coverlistitem.h"
#include <QGraphicsDropShadowEffect>

HomeScreen::HomeScreen(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);
	
	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(10);
	this->m_ui.lb_lastAdded->setFont(nunito);
	this->m_ui.lb_incomingReleases->setFont(nunito);
	this->m_ui.lb_favouriteGames->setFont(nunito);
	this->m_ui.bt_seeLastAdded->setFont(nunito);
	this->m_ui.bt_seeIncomingReleases->setFont(nunito);
	this->m_ui.bt_seeFavouriteGames->setFont(nunito);

	nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
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
	
	RefreshGamesLists();
}

HomeScreen::~HomeScreen()
{
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

