#include "regular-price.hpp"
#include "movie.hpp"

int RegularPrice::getPriceCode() const
{
	return Movie::REGULAR;
}

std::unique_ptr<Price> RegularPrice::clonePrice()
{
	return std::make_unique<RegularPrice>(*this);
}

double RegularPrice::getCharge(int daysRented) const
{
	double result = 0;
	result += 2;
	if(daysRented > 2)
		result += (daysRented - 2) * 1.5;
	return result;
}
