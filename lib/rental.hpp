#pragma once

#include <movie.hpp>

class Rental {
public:
    Rental(Movie movie, int daysRented);

    const Movie& getMovie() const;
    int getDaysRented() const;

	double getCharge() const;

	int getFrequentRenterPoints() const;

private:
    Movie movie;
    int daysRented;
};