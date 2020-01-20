#include "gameinfo.h"
#include <QGraphicsDropShadowEffect>
#include "fonts.h"

GameInfo::GameInfo(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);

	connect(this->m_ui.bt_editGame, &QPushButton::clicked, this, &GameInfo::bt_editGame);
	connect(this->m_ui.bt_favourite, &QPushButton::clicked, this, &GameInfo::bt_favouriteClicked);

	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_cover->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.tabWidget->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_summary->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_title->setGraphicsEffect(shadowEffect);

	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.lb_releasedate->setGraphicsEffect(shadowEffect);
	
	shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(20);
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->m_ui.bt_editGame->setGraphicsEffect(shadowEffect);

	QFont nunito = Fonts::GetFont(Fonts::FontNames::NunitoSemiBold);
	nunito.setPointSize(12);
	this->m_ui.lb_summary->setFont(nunito);

}

GameInfo::~GameInfo()
{
}

void GameInfo::LoadGame(const std::string & title)
{
	this->m_gameShown.Read(title);
	UpdateGameInfo();
}

void GameInfo::UpdateGameInfo()
{
	m_ui.lb_title->setText(QString::fromStdString(m_gameShown.GetTitle()));
	m_ui.lb_summary->setText(QString::fromStdString(m_gameShown.GetSummary()));
	m_ui.lb_releasedate->setText(QString::fromStdString(m_gameShown.GetReleaseDate()));

	std::string coverFile = "designResources/covers/" + m_gameShown.GetTitle() + ".jpg";
	std::replace(std::begin(coverFile), std::end(coverFile), ':', ';');
	QPixmap p(coverFile.c_str()); // load pixmap
	m_ui.lb_cover->setPixmap(p);
	
}

void GameInfo::bt_editGame() {
	emit goEdit(&this->m_gameShown);
}

void GameInfo::bt_favouriteClicked() {
	m_ui.bt_favourite->ToggleFavourited();
}
