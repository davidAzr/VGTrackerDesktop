#pragma once

#include <QWidget>

#include "ui_coverListItem.h"


class CoverListItem : public QWidget
{
	Q_OBJECT

public:
	CoverListItem(QWidget* _parent, const std::string& title);
	~CoverListItem();

	std::string GetTitle();

protected:
	Ui::CoverListItem m_ui;
};
