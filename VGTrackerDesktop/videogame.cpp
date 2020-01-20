#include "videogame.h"


SearchParams::SearchParams(bool launched, bool favourite, std::string title, SearchOrder order, bool incomingReleases) : launched(launched), favourite(favourite), title(title), order(order), incomingReleases(incomingReleases) {

}

SearchParams::SearchParams() : launched(0), favourite(0), title("%%"), order(SearchOrder::None), incomingReleases(0) {

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

