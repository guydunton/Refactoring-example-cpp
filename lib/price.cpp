#include "price.hpp"
#include "movie.hpp"

int Price::getFrequentRenterPoints(int daysRented) const
{
	int frequentRenterPoints = 0;

	// Add frequent renter points
	frequentRenterPoints++;

	// add bonus for a 2 day new price release rental
	if (getPriceCode() == Movie::NEW_RELEASE && daysRented > 1)
		frequentRenterPoints++;

	return frequentRenterPoints;
}
