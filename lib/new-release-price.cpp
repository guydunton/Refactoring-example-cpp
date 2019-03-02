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
