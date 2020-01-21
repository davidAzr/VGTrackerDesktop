#include "library.h"
#include "coverlistitem.h"
#include "fonts.h"
#include <QGraphicsDropShadowEffect>

Library::Library(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);

	connect(m_ui.lw_library, &QListWidget::itemClicked, this, &Library::lw_gameSelected);
	connect(m_ui.bt_addGame, &QPushButton::clicked, this, &Library::bt_addGameClicked);

	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.lb_library->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(30);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.fr_filtersHolder->setGraphicsEffect(shadowEffect);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(9);
	m_ui.ck_favourite->setFont(nunito);
	m_ui.ck_launched->setFont(nunito);
	m_ui.lb_order->setFont(nunito);
	m_ui.cb_order->setFont(nunito);
	m_ui.le_searchBar->setFont(nunito);
	m_ui.ck_favourite->setFont(nunito);
	m_ui.ck_launched->setFont(nunito);
	m_ui.lb_order->setFont(nunito);
	m_ui.cb_order->setFont(nunito);
	m_ui.le_searchBar->setFont(nunito);
	nunito.setPointSize(12);
	m_ui.bt_addGame->setFont(nunito);
	nunito.setPointSize(13);
	m_ui.lb_noGames->setFont(nunito);
	//nunito.setPointSize(17);
	//m_ui.lb_title->setFont(nunito);
	
	this->RefreshGamesList();
	
	// Filters
	connect(m_ui.le_searchBar, &QLineEdit::returnPressed, this, qOverload<>(&Library::FiltersUpdated));
	connect(m_ui.ck_favourite, &QCheckBox::clicked, this, qOverload<>(&Library::FiltersUpdated));
	connect(m_ui.ck_launched, &QCheckBox::clicked, this, qOverload<>(&Library::FiltersUpdated));
	connect(m_ui.cb_order, qOverload<int>(&QComboBox::currentIndexChanged), this, qOverload<>(&Library::FiltersUpdated));
}

Library::~Library()
{
}

void Library::RefreshGamesList(std::vector<Videogame> libraryGames) {
	m_ui.lw_library->clear();
	if (libraryGames.size() == 0) {
		m_ui.lw_library->setVisible(false);
		m_ui.lb_noGames->setVisible(true);
	}
	else {
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

		m_ui.lb_noGames->setVisible(false);
		m_ui.lw_library->setVisible(true);
	}
}

void Library::RefreshGamesList() {
	this->FiltersUpdated();
}

void Library::lw_gameSelected()
{
	std::string selectedGameTitle = dynamic_cast<CoverListItem*>(m_ui.lw_library->itemWidget(m_ui.lw_library->currentItem()))->GetTitle();
	emit gameSelected(selectedGameTitle);
}

void Library::bt_addGameClicked()
{
	emit addGame();
}

void Library::FiltersUpdated()
{
	std::vector<Videogame> searchResults;
	SearchParams filters(m_ui.ck_launched->isChecked(), m_ui.ck_favourite->isChecked(), m_ui.le_searchBar->text().toStdString(), (SearchOrder)(m_ui.cb_order->currentIndex()));
	searchResults = Videogame::Search(filters);
	RefreshGamesList(searchResults);
}

void Library::FiltersUpdated(SearchParams filters)
{
	std::vector<Videogame> searchResults = Videogame::Search(filters);
	RefreshGamesList(searchResults);
}
