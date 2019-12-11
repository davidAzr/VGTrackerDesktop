#include "VGTrackerDesktop.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VGTrackerDesktop w;
	w.show();
	return a.exec();
}
