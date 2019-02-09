#pragma once

#include <string>

class Movie {
public:
    static const int CHILDREN = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

    Movie(std::string title, int priceCode);

    const std::string& getTitle() const;

    int getPriceCode() const;
    void setPriceCode(int priceCode);

private:
    std::string title;
    int priceCode;
};