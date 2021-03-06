﻿#include "new-release-price.hpp"
#include "movie.hpp"

int NewReleasePrice::getPriceCode() const
{
	return Movie::NEW_RELEASE;
}

std::unique_ptr<Price> NewReleasePrice::clonePrice()
{
	return std::make_unique<NewReleasePrice>(*this);
}

double NewReleasePrice::getCharge(int daysRented) const
{
	return daysRented * 3;
}

int NewReleasePrice::getFrequentRenterPoints(int daysRented) const
{
	const int basePoints = Price::getFrequentRenterPoints(daysRented);

	if (daysRented > 1)
		return basePoints + 1;
	
	return basePoints;
}
