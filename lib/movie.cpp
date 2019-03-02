#include "movie.hpp"
#include <cassert>
#include "childrens-price.hpp"
#include "new-release-price.hpp"
#include "regular-price.hpp"

Movie::Movie(std::string title, int priceCode) :
    title{ std::move(title) }
{
	setPriceCode(priceCode);
}

Movie::Movie(const Movie& other) : 
	title{ other.title },
	price{ other.price->clonePrice() }
{}

Movie& Movie::operator=(const Movie& other)
{
	title = other.title;
	price = other.price->clonePrice();
	return *this;
}

Movie& Movie::operator=(Movie&& other) noexcept
{
	std::swap(*this, other);
	return *this;
}

const std::string& Movie::getTitle() const
{
    return title;
}

int Movie::getPriceCode() const
{
    return price->getPriceCode();
}

void Movie::setPriceCode(int priceCode)
{
	switch (priceCode) 
	{
	case Movie::REGULAR:
		price = std::make_unique<RegularPrice>();
		break;
	case Movie::NEW_RELEASE:
		price = std::make_unique<NewReleasePrice>();
		break;
	case Movie::CHILDREN:
		price = std::make_unique<ChildrensPrice>();
		break;
	default:
		using namespace std::string_literals;
		const std::string error = "Invalid price code: "s + std::to_string(priceCode);
		throw std::invalid_argument(error);
	}
}

double Movie::getCharge(int daysRented) const
{
	return price->getCharge(daysRented);
}

int Movie::getFrequentRenterPoints(int daysRented) const
{
	return price->getFrequentRenterPoints(daysRented);
}
