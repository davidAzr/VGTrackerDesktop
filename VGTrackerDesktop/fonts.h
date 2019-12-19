#pragma once

#include <QWidget>
#include <QFontDatabase>

class Fonts {
public:
	enum FontNames {
		NunitoBlack = 0,
		NunitoBlackItalic,
		NunitoBold,
		NunitoBoldItalic,
		NunitoExtraBold,
		NunitoExtraBoldItalic,
		NunitoExtraLight,
		NunitoExtraLightItalic,
		NunitoItalic,
		NunitoLight,
		NunitoLightItalic,
		NunitoRegular,
		NunitoSemiBold,
		NunitoSemiBoldItalic
	};

	static void addFontsToApplication() {
		indexes.clear();
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Black.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-BlackItalic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Bold.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-BoldItalic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-ExtraBold.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-ExtraBoldItalic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-ExtraLight.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-ExtraLightItalic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Italic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Light.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-LightItalic.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-Regular.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-SemiBold.ttf"));
		indexes.push_back(QFontDatabase::addApplicationFont("designResources/fonts/Nunito/Nunito-SemiBoldItalic.ttf"));
	}

	static QFont GetFont(FontNames font) {
		QString family = QFontDatabase::applicationFontFamilies(indexes.at(font)).at(0);
		return QFont(family);
	}

private:
	static std::vector<int> indexes;
};