#include "library.h"
#include "coverlistitem.h"
#include "fonts.h"
Library::Library(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);

	connect(this->m_ui.lw_library, &QListWidget::itemClicked, this, &Library::lw_gameSelected);
	connect(this->m_ui.bt_addGame, &QPushButton::clicked, this, &Library::bt_addGameClicked);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoRegular);
	this->setFont(nunito);

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

	this->setFont(nunito);
}

Library::~Library()
{
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
