#include "gameinfo.h"
#include <QGraphicsDropShadowEffect>
#include "fonts.h"
#include "notelistitem.h"

GameInfo::GameInfo(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);

	connect(m_ui.bt_editGame, &QPushButton::clicked, this, &GameInfo::bt_editGame);
	connect(m_ui.bt_favourite, &QPushButton::clicked, this, &GameInfo::bt_favouriteClicked);

	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.lb_cover->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.tabWidget->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.lb_summary->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.lb_title->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.lb_releasedate->setGraphicsEffect(shadowEffect);
	
	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	m_ui.bt_editGame->setGraphicsEffect(shadowEffect);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoSemiBold);
	nunito.setPointSize(11);
	m_ui.lb_summary->setFont(nunito);

	nunito.setPointSize(10);
	m_ui.tabWidget->tabBar()->setFont(nunito);
	
	nunito = Fonts::GetFont(Fonts::FontNames::NunitoExtraBold);
	nunito.setPointSize(9);
	m_ui.te_newNote->setFont(nunito);
	QColor newNoteColor;
	newNoteColor.setNamedColor("white");
	m_ui.te_newNote->setTextColor(newNoteColor);
	

	//std::string itemNameStr = videogame.GetTitle();
	NoteListItem* newRealItem = new NoteListItem(this);
	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	//newRealItem->setGraphicsEffect(shadowEffect);
	QListWidgetItem* newItem = new QListWidgetItem();
	newItem->setSizeHint(newRealItem->sizeHint());
	m_ui.lw_noteList->addItem(newItem);
	m_ui.lw_noteList->setItemWidget(newItem, newRealItem);

	newRealItem = new NoteListItem(this);
	newItem = new QListWidgetItem();
	newItem->setSizeHint(newRealItem->sizeHint());
	m_ui.lw_noteList->addItem(newItem);
	m_ui.lw_noteList->setItemWidget(newItem, newRealItem);

	newRealItem = new NoteListItem(this);
	newItem = new QListWidgetItem();
	newItem->setSizeHint(newRealItem->sizeHint());
	m_ui.lw_noteList->addItem(newItem);
	m_ui.lw_noteList->setItemWidget(newItem, newRealItem);

	newRealItem = new NoteListItem(this);
	newItem = new QListWidgetItem();
	newItem->setSizeHint(newRealItem->sizeHint());
	m_ui.lw_noteList->addItem(newItem);
	m_ui.lw_noteList->setItemWidget(newItem, newRealItem);

	m_ui.lw_noteList->ResizeToContents();

}

GameInfo::~GameInfo()
{
}

void GameInfo::LoadGame(const std::string & title)
{
	m_gameShown.Read(title);
	UpdateGameInfo();
}

void GameInfo::UpdateGameInfo()
{
	m_ui.lb_title->setText(QString::fromStdString(m_gameShown.GetTitle()));
	m_ui.lb_summary->setText(QString::fromStdString(m_gameShown.GetSummary()));
	m_ui.lb_releasedate->setText(QString::fromStdString(m_gameShown.GetReleaseDate()));
	m_ui.bt_favourite->ResetFavourited();

	if (m_gameShown.GetFavourite()) {
		m_ui.bt_favourite->ToggleFavourited();
	}

	std::string coverFile = "designResources/covers/" + m_gameShown.GetTitle() + ".jpg";
	std::replace(std::begin(coverFile), std::end(coverFile), ':', ';');
	QPixmap p(coverFile.c_str()); // load pixmap
	m_ui.lb_cover->setPixmap(p);
	
}

void GameInfo::bt_editGame() {
	emit goEdit(&m_gameShown);
}

void GameInfo::bt_favouriteClicked() {
	m_ui.bt_favourite->ToggleFavourited();
	m_gameShown.ToggleFavourite();
	m_gameShown.Update();
}
