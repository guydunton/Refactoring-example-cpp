#include "customer.hpp"
#include <movie.hpp>
#include <numeric>


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

double Customer::getTotalAmount() const
{
	const auto sumFunc = [](auto current, const auto& rental)
		{ return current + rental.getCharge(); };
	return std::accumulate(rentals.begin(), rentals.end(), 0.0, sumFunc);
	
}

int Customer::getTotalRenterPoints() const
{
	const auto sumFunc = [](auto current, const auto& rental) 
		{ return current + rental.getFrequentRenterPoints(); };
	return std::accumulate(rentals.begin(), rentals.end(), 0, sumFunc);
}

std::string Customer::statement() const
{
    using namespace std::string_literals;

	std::string result = "Rental record for "s + getName() + "\n"s;
    for(const auto& rental : rentals)
    {
        // show figures for this rental
        result += "\t"s + rental.getMovie().getTitle() + "\t"s + std::to_string(rental.getCharge()) + "\n"s;
    }

    // add footer lines
    result += "Amount owed is "s + std::to_string(getTotalAmount()) + "\n"s;
    result += "You earned "s + std::to_string(getTotalRenterPoints()) + " frequent renter points"s;

    return result;
}

std::string Customer::htmlStatement() const
{
	using namespace std::string_literals;

	std::string result = "<H1>Rentals for <EM>"s + getName() + "</EM></H1><P>"s + "\n"s;
	for (const auto& rental : rentals) 
	{
		// Show figures for each rental
		result += rental.getMovie().getTitle() + ": "s + std::to_string(rental.getCharge()) + "<BR>"s + "\n"s;
	}

	// add footer lines
	result += "<P>You owe <EM>"s + std::to_string(getTotalAmount()) + "</EM><P>"s + "\n"s;
	result += "On this rental you earned <EM>" + std::to_string(getTotalRenterPoints()) + "</EM> frequent renter points<P>"s;

	return result;
}
