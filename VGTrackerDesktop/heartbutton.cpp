#include "heartbutton.h"
#include "QGraphicsDropShadowEffect"

HeartButton::HeartButton(QWidget *parent)
	: QPushButton(parent), m_heart("designResources/icons/heart.png"), m_redheart("designResources/icons/heartred.png"), m_darkredheart("designResources/icons/heartdarkred.png")
{
	m_favourited = false;

	connect(this, &QPushButton::pressed, this, [&] {this->setIconSize(QSize(48, 48)); });
	connect(this, &QPushButton::released, this, [&] {
		this->setIconSize(QSize(52, 52)); 
		if (m_favourited) {
			this->setIcon(m_heart);
		}
	});

	this->setIconSize(QSize(48, 48));
	this->setIcon(m_heart);

	QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect();
	shadowEffect->setBlurRadius(40);
	QColor shadowColor;
	shadowColor.setNamedColor("black");
	shadowEffect->setColor(shadowColor);
	this->setGraphicsEffect(shadowEffect);
}

HeartButton::~HeartButton()
{
}

void HeartButton::enterEvent(QEvent* e)
{
	this->setIconSize(QSize(52, 52));
	this->setIcon(m_redheart);
	QWidget::enterEvent(e);
}

void HeartButton::leaveEvent(QEvent* e)
{
	if (!m_favourited) {
		this->setIconSize(QSize(48, 48));
		this->setIcon(m_heart);
	}
	else {
		this->setIconSize(QSize(48, 48));
		this->setIcon(m_darkredheart);
	}
	QWidget::enterEvent(e);
}