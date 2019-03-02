#pragma once

#include <rental.hpp>
#include <string>
#include <vector>

class Customer {
public:
    explicit Customer(std::string name);

    const std::string& getName() const;
    void addRental(Rental rental);

	std::string statement() const;
	std::string htmlStatement() const;

private:

	double getTotalAmount() const;
	int getTotalRenterPoints() const;

    std::string name;
    std::vector<Rental> rentals;
};