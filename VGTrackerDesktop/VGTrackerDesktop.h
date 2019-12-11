#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VGTrackerDesktop.h"

class VGTrackerDesktop : public QMainWindow
{
	Q_OBJECT

public:
	VGTrackerDesktop(QWidget *parent = Q_NULLPTR);

private:
	Ui::VGTrackerDesktopClass ui;
};
