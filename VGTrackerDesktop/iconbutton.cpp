#include "iconbutton.h"

IconButton::IconButton(QWidget *parent)
	: QPushButton(parent)
{
	connect(this, &QPushButton::pressed, this, [&] {
		this->setIconSize(QSize(16, 16)); 
	});
	connect(this, &QPushButton::released, this, [&] {
		this->setIconSize(QSize(17, 17));
	});
	
	QSize buttonSize(20, 20);
	this->setFixedSize(buttonSize);
}

IconButton::~IconButton()
{
}

void IconButton::enterEvent(QEvent * e)
{
	this->setIconSize(QSize(17, 17));
	QWidget::enterEvent(e);
}

void IconButton::leaveEvent(QEvent * e)
{
	this->setIconSize(QSize(16, 16));
	QWidget::enterEvent(e);
}
\