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

protected slots:
	//void resizeEvent(QResizeEvent *event) override;

protected:
	Ui::coverListItem m_ui;
};
