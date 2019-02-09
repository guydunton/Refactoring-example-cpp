#include "movie.hpp"

Movie::Movie(std::string title, int priceCode) :
    title{ std::move(title) },
    priceCode{ priceCode }
{
}

const std::string& Movie::getTitle() const
{
    return title;
}

int Movie::getPriceCode() const
{
    return priceCode;
}

void Movie::setPriceCode(int priceCode)
{
    this->priceCode = priceCode;
}