#pragma once
#include "price.hpp"

class NewReleasePrice : public Price
{
public:
	int getPriceCode() const override;
	std::unique_ptr<Price> clonePrice() override;
};
