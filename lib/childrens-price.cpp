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

double ChildrensPrice::getCharge(int daysRented) const
{
	double result = 0;
	result += 1.5;
	if (daysRented > 3)
		result += (daysRented - 3) * 1.5;
	return result;
}
