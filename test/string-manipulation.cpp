#include "string-manipulation.hpp"
#include <sstream>


std::vector<std::string> split(const std::string& text, char delim)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(text);

	while (std::getline(tokenStream, token, delim)) {
		tokens.push_back(token);
	}

	return tokens;
}