//#include "VGTrackerDesktop.h"
#include "VGTrackerMainWindow.h"
#include <QtWidgets/QApplication>

//#include "stdafx.h"
#include <mysql.h>
#include <iostream>

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
	//VGTrackerDesktop w;
	VGTrackerMainWindow w(NULL);
	QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
	w.show();
	return a.exec();
}
