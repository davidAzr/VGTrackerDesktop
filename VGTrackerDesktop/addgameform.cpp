#include "addgameform.h"
#include "auxiliary.h"

#include <filesystem>

#include <QFileDialog>

AddGameForm::AddGameForm(QWidget *parent)
	: QWidget(parent)
{
	m_ui.setupUi(this);
	connect(m_ui.bt_searchCover, &QPushButton::clicked, this, &AddGameForm::GetSelectedFile);
	connect(m_ui.bt_add, &QPushButton::clicked, this, &AddGameForm::bt_addClicked);
}

AddGameForm::~AddGameForm()
{
}

void AddGameForm::Reset()
{
	//Reset videogame
	m_videogame = std::make_unique<Videogame>();

	//Clear UI elements
	m_ui.le_title->clear();
	m_ui.te_summary->clear();
	m_ui.de_releaseDate->clear();
	m_ui.lb_coverPath->setText("No file selected");
	m_ui.lb_coverPrev->clear();
	m_ui.lb_coverMsg->clear();
}

void AddGameForm::GetSelectedFile()
{
	QString coverFilePath = QFileDialog::getOpenFileName(this, tr("Select cover file"), "", tr("Images (*.jpg)"));
	m_ui.lb_coverPath->setText(coverFilePath);
	auto maxH = m_ui.lb_coverPrev->maximumHeight();
	QPixmap p(coverFilePath); // load pixmap
	// set a scaled pixmap to a w x h window keeping its aspect ratio 
	m_ui.lb_coverPrev->setPixmap(p.scaledToHeight(maxH));
}
void AddGameForm::bt_addClicked()
{
	//Check if the title has been introduced
	if (m_ui.le_title->text().isEmpty()) {
		//No title entered error
		return;
	}
	else {
		m_videogame->SetTitle(m_ui.le_title->text().toStdString());
		m_videogame->SetSummary(m_ui.te_summary->toPlainText().toStdString());
		
		const std::string dateStr = m_ui.de_releaseDate->text().toStdString();

		if (dateStr != "01/01/2000") {

			std::string year, month, day, sqlDate;
			auto endDay = dateStr.find('/', 0);
			auto endMonth = dateStr.find('/', endDay + 1);
			auto endYear = dateStr.find('/', endMonth + 1);

			day = dateStr.substr(0, endDay);
			month = dateStr.substr(endDay + 1, endMonth - (endDay + 1));
			year = dateStr.substr(endMonth + 1);

			sqlDate = year + "-" + month + "-" + day;

			m_videogame->SetReleaseDate(sqlDate);
		}
		else {
			m_videogame->SetReleaseDate(std::string("NOT SET"));
		}

		std::string newFilePath = "designResources/covers/" + TransformTitleToFilename(m_ui.le_title->text().toStdString()) + ".jpg";
		
		if (std::filesystem::exists(m_ui.lb_coverPath->text().toStdString())) {
			if (std::filesystem::exists(newFilePath)) {
				std::filesystem::remove(newFilePath);
			}
			std::filesystem::copy_file(m_ui.lb_coverPath->text().toStdString(), newFilePath);
		}
		
	
		bool updateLibrary = m_videogame->Save();
		SearchParams params;
		emit goLibrary(updateLibrary, params);
	}
}


