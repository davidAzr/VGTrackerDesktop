#pragma once

#include <QWidget>
#include <QListWidgetItem>

#include "ui_coverListItem.h"


class CoverListItem : public QWidget
{
	Q_OBJECT

public:
	CoverListItem();
	~CoverListItem();

protected:
	Ui::coverListItem m_ui;
};
