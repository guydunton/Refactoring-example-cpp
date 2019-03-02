#pragma once
#include "catch.hpp"
#include "string-manipulation.hpp"
#include <string>

inline void checkSame(const std::string& precomputed, const std::string& calculated)
{
	const auto splitPrecomputed = split(precomputed, '\n');
	const auto splitStatement = split(calculated, '\n');

	REQUIRE(splitPrecomputed.size() == splitStatement.size());

	for (size_t i = 0; i < splitPrecomputed.size(); ++i) {
		const auto& precompText = splitPrecomputed.at(i);
		const auto& statementText = splitStatement.at(i);

		INFO("Precomputed line: " << precompText);
		INFO("Calculated line: " << statementText);
		REQUIRE(precompText == statementText);
	}
}