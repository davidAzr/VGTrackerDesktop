#pragma once

#include <QPushButton>

class IconButton : public QPushButton
{
	Q_OBJECT

public:
	IconButton(QWidget *parent);
	~IconButton();

protected:
	QIcon m_clickableIcon;

	virtual void enterEvent(QEvent* e) override;
	virtual void leaveEvent(QEvent* e) override;
};
