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

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(9);
	this->m_ui.ck_favourite->setFont(nunito);
	this->m_ui.ck_launched->setFont(nunito);
	this->m_ui.lb_order->setFont(nunito);
	this->m_ui.cb_order->setFont(nunito);
	this->m_ui.le_searchBar->setFont(nunito);
	this->m_ui.ck_favourite->setFont(nunito);
	this->m_ui.ck_launched->setFont(nunito);
	this->m_ui.lb_order->setFont(nunito);
	this->m_ui.cb_order->setFont(nunito);
	this->m_ui.le_searchBar->setFont(nunito);
	
	this->RefreshGamesList();
	
	// Filters
	connect(this->m_ui.le_searchBar, &QLineEdit::returnPressed, this, &Library::FiltersUpdated);
	connect(this->m_ui.ck_favourite, &QCheckBox::clicked, this, &Library::FiltersUpdated);
	connect(this->m_ui.ck_launched, &QCheckBox::clicked, this, &Library::FiltersUpdated);
	connect(this->m_ui.cb_order, qOverload<int>(&QComboBox::currentIndexChanged), this, &Library::FiltersUpdated);
}

Library::~Library()
{
}

std::vector<Videogame> libraryGames = Videogame::AllGames();

void Library::RefreshGamesList(std::vector<Videogame> libraryGames) {
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

void Library::RefreshGamesList() {
	this->FiltersUpdated();
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

void Library::FiltersUpdated()
{
	std::vector<Videogame> searchResults;
	SearchParams filters(m_ui.ck_launched->isChecked(), m_ui.ck_favourite->isChecked(), m_ui.le_searchBar->text().toStdString(), (SearchOrder)(m_ui.cb_order->currentIndex()));
	searchResults = Videogame::Search(filters);
	RefreshGamesList(searchResults);
}
