#include "homescreen.h"
#include "fonts.h"
#include "videogame.h"
#include "coverlistitem.h"
#include <QGraphicsDropShadowEffect>

HomeScreen::HomeScreen(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoBlackItalic);
	this->m_ui.scrollAreaWidgetContents->setFont(nunito);
	this->m_ui.scrollArea->setFont(nunito);
	this->m_ui.lb_lastAdded->setFont(nunito);
	this->m_ui.lb_incomingReleases->setFont(nunito);
	this->m_ui.lb_favouriteGames->setFont(nunito);
	this->m_ui.bt_seeLastAdded->setFont(nunito);

	RefreshGamesLists();
}

HomeScreen::~HomeScreen()
{
}
void HomeScreen::RefreshGamesLists() {
	std::vector<Videogame> gameList = Videogame::AllGames();
	this->m_ui.lw_favouriteGames->clear();
	this->m_ui.lw_incomingReleases->clear();
	this->m_ui.lw_lastAdded->clear();
	std::for_each(begin(gameList), end(gameList),
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

	std::for_each(begin(gameList), end(gameList),
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
	
	std::for_each(begin(gameList), end(gameList),
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
}

