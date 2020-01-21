#pragma once

#include <QPushButton>

class HeartButton : public QPushButton
{
	Q_OBJECT

protected:
	bool m_favourited;
	QIcon m_heart, m_redheart, m_darkredheart;
	
	virtual void enterEvent(QEvent* e) override;
	virtual void leaveEvent(QEvent* e) override;


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

	void ResetFavourited() {
		m_favourited = false;
		this->setIcon(m_heart);
	}
};
