#pragma once

#include <QPushButton>

class HeartButton : public QPushButton
{
	Q_OBJECT

protected:
	bool m_favourited;
	QIcon m_heart, m_redheart, m_darkredheart;
	
	virtual void enterEvent(QEvent* e);
	virtual void leaveEvent(QEvent* e);


public:
	HeartButton(QWidget *parent);
	~HeartButton();

	void ToggleFavourited() {
		m_favourited = !m_favourited;
		if (m_favourited) {
			this->setIcon(m_darkredheart);
		}
		else {
			this->setIcon(m_heart);
		}
	}
};
