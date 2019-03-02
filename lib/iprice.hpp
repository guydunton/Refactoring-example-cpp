#pragma once
#include <memory>

class IPrice
{
public:
	virtual int getPriceCode() const = 0;
	virtual std::unique_ptr<IPrice> clonePrice() = 0;

	virtual ~IPrice() = default;
};
