#include "childrens-price.hpp"
#include "movie.hpp"

int ChildrensPrice::getPriceCode() const
{
	return Movie::CHILDREN;
}

std::unique_ptr<Price> ChildrensPrice::clonePrice()
{
	return std::make_unique<ChildrensPrice>(*this);
}
