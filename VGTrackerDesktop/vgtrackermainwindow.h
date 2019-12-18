#pragma once

#include <QWidget>

#include "ui_VGTrackerMainWindow.h"

class VGTrackerMainWindow : public QWidget
{
	Q_OBJECT

public:
	VGTrackerMainWindow(QWidget *parent);
	~VGTrackerMainWindow();
protected:
	Ui::VGTrackerMain m_ui;
};
