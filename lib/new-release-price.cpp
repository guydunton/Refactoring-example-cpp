#include "new-release-price.hpp"
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
	double result = 0;
	result += daysRented * 3;
	return result;
}
