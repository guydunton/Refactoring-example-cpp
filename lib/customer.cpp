#include "customer.hpp"
#include <movie.hpp>

Customer::Customer(std::string name) :
    name{ std::move(name) }
{
}

const std::string& Customer::getName() const
{
    return name;
}

void Customer::addRental(Rental rental)
{
    rentals.emplace_back(std::move(rental));
}



std::string Customer::statement() const
{
    using namespace std::string_literals;

    double totalAmount = 0;
    int frequentRenterPoints = 0;
	
	std::string result = "Rental record for "s + getName() + "\n"s;
    for(const auto& rental : rentals)
    {
        const double amount = rental.getCharge();

        // Add frquent renter points
        frequentRenterPoints++;

        // add bonus for a 2 day new price release rental
        if (rental.getMovie().getPriceCode() == Movie::NEW_RELEASE && rental.getDaysRented() > 1)
            frequentRenterPoints++;

        // show figures for this rental
        result += "\t"s + rental.getMovie().getTitle() + "\t"s + std::to_string(amount) + "\n"s;

        totalAmount += amount;
    }

    // add footer lines
    result += "Amount owed is "s + std::to_string(totalAmount) + "\n"s;
    result += "You earned "s + std::to_string(frequentRenterPoints) + " frequent renter points"s;

    return result;
}
