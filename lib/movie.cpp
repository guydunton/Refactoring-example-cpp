#include "movie.hpp"

Movie::Movie(std::string title, int priceCode) :
    title{ std::move(title) },
    priceCode{ priceCode }
{
}

const std::string& Movie::getTitle() const
{
    return title;
}

int Movie::getPriceCode() const
{
    return priceCode;
}

void Movie::setPriceCode(int priceCode)
{
    this->priceCode = priceCode;
}

double Movie::getCharge(int daysRented) const
{
	double result = 0;
	switch (getPriceCode())
	{
	case Movie::REGULAR:
		result += 2;
		if (daysRented > 2)
			result += (daysRented - 2) * 1.5;
		break;
	case Movie::NEW_RELEASE:
		result += daysRented * 3;
		break;
	case Movie::CHILDREN:
		result += 1.5;
		if (daysRented > 3)
			result += (daysRented - 3) * 1.5;
		break;
	}
	return result;
}
