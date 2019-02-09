#include <customer.hpp>
#include <movie.hpp>
#include <rental.hpp>
#include <iostream>
#include <string>

int main()
{
    using namespace std::string_literals;

    Movie spiderman{ "Spiderman"s, 0 };
    Movie monsters_inc{ "Monsters Inc"s, 2 };

    Customer guy{ "Guy"s };
    guy.addRental(Rental{ spiderman, 28 });
    guy.addRental(Rental{ monsters_inc, 10 });
    
    std::cout << guy.statement() << "\n";

	Customer customer1{ "Jim" };
	const Movie film{ "Cars", Movie::NEW_RELEASE };
	customer1.addRental(Rental{ film, 1 });

	std::cout << customer1.statement() << "\n";

    return 0;
}