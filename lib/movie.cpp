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

int Movie::getFrequentRenterPoints(int daysRented) const
{
	int frequentRenterPoints = 0;

	// Add frequent renter points
	frequentRenterPoints++;

	// add bonus for a 2 day new price release rental
	if (getPriceCode() == Movie::NEW_RELEASE && daysRented > 1)
		frequentRenterPoints++;

	return frequentRenterPoints;
}
