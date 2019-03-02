#pragma once
#include <memory>

class Price
{
public:
	virtual int getPriceCode() const = 0;
	virtual std::unique_ptr<Price> clonePrice() = 0;

	virtual ~Price() = default;
};
