#include "editgameform.h"
#include "auxiliary.h"
#include <filesystem>

EditGameForm::EditGameForm(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);
	connect(this->m_ui.bt_update, &QPushButton::clicked, this, &EditGameForm::bt_updateClicked);
	connect(this->m_ui.bt_delete, &QPushButton::clicked, this, &EditGameForm::bt_deleteClicked);
	
}

EditGameForm::~EditGameForm()
{
}

void EditGameForm::SetUp(Videogame * videogame)
{
	m_videogame = videogame;
	this->m_ui.le_title->setText(QString::fromStdString(m_videogame->GetTitle()));
	this->m_ui.te_summary->setText(QString::fromStdString(m_videogame->GetSummary()));
}

void EditGameForm::bt_deleteClicked() {
	m_videogame->Delete();
	emit goLibrary(true);
}

void EditGameForm::bt_updateClicked() {
	this->m_videogame->SetSummary(this->m_ui.te_summary->toPlainText().toStdString());

	const std::string dateStr = this->m_ui.de_releaseDate->text().toStdString();
	if (dateStr != "01/01/2000") {

		std::string year, month, day, sqlDate;
		auto endDay = dateStr.find('/', 0);
		auto endMonth = dateStr.find('/', endDay + 1);
		auto endYear = dateStr.find('/', endMonth + 1);

		day = dateStr.substr(0, endDay);
		month = dateStr.substr(endDay + 1, endMonth - (endDay + 1));
		year = dateStr.substr(endMonth + 1);

		sqlDate = year + "-" + month + "-" + day;

		this->m_videogame->SetSqlReleaseDate(sqlDate);
	}

	std::string newFilePath = "designResources/covers/" + TransformTitleToFilename(this->m_ui.le_title->text().toStdString()) + ".jpg";

	if (std::filesystem::exists(this->m_ui.lb_coverPath->text().toStdString())) {
		if (std::filesystem::exists(newFilePath)) {
			std::filesystem::remove(newFilePath);
		}
		std::filesystem::copy_file(this->m_ui.lb_coverPath->text().toStdString(), newFilePath);
	}

	bool updated = this->m_videogame->Update();
	emit goGameInfo(m_videogame->GetTitle());
}
//const std::string dateStr = this->m_ui.de_releaseDate->text().toStdString();
//if (dateStr != "01/01/2000") {
//
//	std::string year, month, day, sqlDate;
//	auto endDay = dateStr.find('/', 0);
//	auto endMonth = dateStr.find('/', endDay + 1);
//	auto endYear = dateStr.find('/', endMonth + 1);
//
//	day = dateStr.substr(0, endDay);
//	month = dateStr.substr(endDay + 1, endMonth - (endDay + 1));
//	year = dateStr.substr(endMonth + 1);
//
//	sqlDate = year + "-" + month + "-" + day;
//
//	this->m_videogame->SetReleaseDate(sqlDate);
//}
