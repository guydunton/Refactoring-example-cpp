#include "rental.hpp"


Rental::Rental(Movie movie, int daysRented) :
    movie{ std::move(movie) },
    daysRented{ daysRented }
{
}

const Movie& Rental::getMovie() const
{
    return movie;
}

int Rental::getDaysRented() const
{
    return daysRented;
}

double Rental::getCharge() const
{
	return movie.getCharge(daysRented);
}

int Rental::getFrequentRenterPoints() const
{
	int frequentRenterPoints = 0;

	// Add frequent renter points
	frequentRenterPoints++;

	// add bonus for a 2 day new price release rental
	if (getMovie().getPriceCode() == Movie::NEW_RELEASE && getDaysRented() > 1)
		frequentRenterPoints++;

	return frequentRenterPoints;
}
