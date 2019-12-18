#include "vgtrackermainwindow.h"
#include "library.h"

VGTrackerMainWindow::VGTrackerMainWindow(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);
	this->m_ui.lo_widgetholder->addWidget(new Library(this));
}

VGTrackerMainWindow::~VGTrackerMainWindow()
{
}
