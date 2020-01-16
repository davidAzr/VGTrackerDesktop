#include "VGTrackerMainWindow.h"
#include <QtWidgets/QApplication>
#include <QFile>

#include <mysql.h>
#include <iostream>

#include <fonts.h>

int main(int argc, char *argv[])
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "MyNewPass", "testdb", 3306, NULL, 0);

	if (conn) {
		std::string query = "SELECT * FROM test";
		const char* q = query.c_str();
		int qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
			}
		}
	}


	QApplication a(argc, argv);
	
	Fonts::addFontsToApplication();

	QString fileName = "designResources/style.css";

	// Read in the stylesheet
	QFile stylesheet(fileName);
	stylesheet.open(QFile::ReadOnly);
	QString css = QString(stylesheet.readAll());
	stylesheet.close();

	// Apply the stylesheet
	a.setStyleSheet(css);

	VGTrackerMainWindow w(NULL);
	QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);

	w.show();
	return a.exec();
}
