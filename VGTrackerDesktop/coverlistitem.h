#pragma once

#include <QWidget>
#include <QListWidgetItem>

#include "ui_coverListItem.h"


class CoverListItem : public QWidget
{
	Q_OBJECT

public:
	CoverListItem(QWidget* _parent, const std::string& title);
	~CoverListItem();

protected slots:
	//void resizeEvent(QResizeEvent *event) override;

protected:
	Ui::coverListItem m_ui;
};
