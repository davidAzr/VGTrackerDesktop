#include "videogame.h"


SearchParams::SearchParams(bool launched, bool favourite, std::string title, SearchOrder order) : launched(launched), favourite(favourite), title(title), order(order) {

}

Videogame::Videogame()
{
	m_title = "NOT LOADED";
	m_summary = "NOT LOADED";
	m_releaseDate = "NOT LOADED";
}

Videogame::~Videogame()
{
}

