#pragma once
#include "price.hpp"

class ChildrensPrice : public Price
{
public:
	int getPriceCode() const override;
	std::unique_ptr<Price> clonePrice() override;
};
