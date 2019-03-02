#pragma once

#include "price.hpp"
#include <memory>
#include <string>

class Movie {
public:
    static const int CHILDREN = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

    Movie(std::string title, int priceCode);

	Movie(const Movie& other);
	Movie(Movie&& other) noexcept = default;
	Movie& operator=(const Movie& other);
	Movie& operator=(Movie&& other) noexcept;

    const std::string& getTitle() const;

    int getPriceCode() const;
    void setPriceCode(int priceCode);

	double getCharge(int daysRented) const;
	int getFrequentRenterPoints(int daysRented) const;

	~Movie() = default;
private:
    std::string title;
	std::unique_ptr<Price> price;
};