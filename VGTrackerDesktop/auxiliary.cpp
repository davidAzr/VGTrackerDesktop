#include "auxiliary.h"

std::string TransformTitleToFilename(const std::string& title) {
	const std::string forbiddenCharacters = "<>:\"\\/|?*";
	std::string filename = title;
	std::replace_if(std::begin(filename), std::end(filename),
		[&forbiddenCharacters](char c) -> bool {
		return forbiddenCharacters.find(c) != std::string::npos;
	},
		';');
	return filename;
}