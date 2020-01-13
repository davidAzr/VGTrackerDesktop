#include "library.h"
#include "coverlistitem.h"
#include "fonts.h"
#include <QGraphicsDropShadowEffect>

Library::Library(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);

	connect(this->m_ui.lw_library, &QListWidget::itemClicked, this, &Library::lw_gameSelected);
	connect(this->m_ui.bt_addGame, &QPushButton::clicked, this, &Library::bt_addGameClicked);

	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_library->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(30);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.fr_filtersHolder->setGraphicsEffect(shadowEffect);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoRegular);
	this->setFont(nunito);
	
	this->RefreshGamesList();
}

Library::~Library()
{
}

void Library::RefreshGamesList() {
	std::vector<Videogame> libraryGames = Videogame::AllGames();
	this->m_ui.lw_library->clear();
	std::for_each(begin(libraryGames), end(libraryGames),
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
		m_ui.lw_library->addItem(newItem);
		m_ui.lw_library->setItemWidget(newItem, newRealItem);
	}
	);
}

void Library::lw_gameSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(this->m_ui.lw_library->itemWidget(this->m_ui.lw_library->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}

void Library::bt_addGameClicked()
{
	emit addGame();
}
