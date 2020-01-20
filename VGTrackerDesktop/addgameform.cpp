#include "addgameform.h"
#include "auxiliary.h"

#include <filesystem>

#include <QFileDialog>

AddGameForm::AddGameForm(QWidget *parent)
	: QWidget(parent)
{
	this->m_ui.setupUi(this);
	connect(this->m_ui.bt_searchCover, &QPushButton::clicked, this, &AddGameForm::GetSelectedFile);
	connect(this->m_ui.bt_add, &QPushButton::clicked, this, &AddGameForm::bt_addClicked);
}

AddGameForm::~AddGameForm()
{
}

void AddGameForm::Reset()
{
	//Reset videogame
	m_videogame = std::make_unique<Videogame>();

	//Clear UI elements
	this->m_ui.le_title->clear();
	this->m_ui.te_summary->clear();
	this->m_ui.de_releaseDate->clear();
	this->m_ui.lb_coverPath->setText("No file selected");
	this->m_ui.lb_coverPrev->clear();
	this->m_ui.lb_coverMsg->clear();
}

void AddGameForm::GetSelectedFile()
{
	QString coverFilePath = QFileDialog::getOpenFileName(this, tr("Select cover file"), "", tr("Images (*.jpg)"));
	this->m_ui.lb_coverPath->setText(coverFilePath);
	auto maxH = this->m_ui.lb_coverPrev->maximumHeight();
	QPixmap p(coverFilePath); // load pixmap
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_coverPrev->setPixmap(p.scaledToHeight(maxH));
}
void AddGameForm::bt_addClicked()
{
	//Check if the title has been introduced
	if (this->m_ui.le_title->text().isEmpty()) {
		//No title entered error
		return;
	}
	else {
		this->m_videogame->SetTitle(this->m_ui.le_title->text().toStdString());
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

			this->m_videogame->SetReleaseDate(sqlDate);
		}
		else {
			this->m_videogame->SetReleaseDate(std::string("NOT SET"));
		}

		std::string newFilePath = "designResources/covers/" + TransformTitleToFilename(this->m_ui.le_title->text().toStdString()) + ".jpg";
		
		if (std::filesystem::exists(this->m_ui.lb_coverPath->text().toStdString())) {
			if (std::filesystem::exists(newFilePath)) {
				std::filesystem::remove(newFilePath);
			}
			std::filesystem::copy_file(this->m_ui.lb_coverPath->text().toStdString(), newFilePath);
		}
		
	
		bool updateLibrary = this->m_videogame->Save();
		SearchParams params;
		emit goLibrary(updateLibrary, params);
	}
}


