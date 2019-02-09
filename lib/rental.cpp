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