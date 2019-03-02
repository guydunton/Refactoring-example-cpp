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
