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
	double result = 0;
	switch (getMovie().getPriceCode())
	{
	case Movie::REGULAR:
		result += 2;
		if (getDaysRented() > 2)
			result += (getDaysRented() - 2) * 1.5;
		break;
	case Movie::NEW_RELEASE:
		result += getDaysRented() * 3;
		break;
	case Movie::CHILDREN:
		result += 1.5;
		if (getDaysRented() > 3)
			result += (getDaysRented() - 3) * 1.5;
		break;
	}
	return result;
}