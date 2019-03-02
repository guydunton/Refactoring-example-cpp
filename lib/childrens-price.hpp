#pragma once
#include "iprice.hpp"

class ChildrensPrice : public IPrice
{
public:
	int getPriceCode() const override;
	std::unique_ptr<IPrice> clonePrice() override;
};
