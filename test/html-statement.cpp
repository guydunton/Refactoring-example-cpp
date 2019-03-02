#include "catch.hpp"
#include <customer.hpp>
#include "check-same.hpp"
#include <string>

TEST_CASE("Customer::htmlStatement produces the correct information")
{
	Customer customer{"Jonathan"};
	const Movie up{"Up", Movie::CHILDREN};
	const Movie bladeRunner{"Blade Runner", Movie::REGULAR};
	const Movie legoMovie{"The Lego Movie", Movie::NEW_RELEASE};

	customer.addRental(Rental{up, 4});
	customer.addRental(Rental{bladeRunner, 10});
	customer.addRental(Rental{legoMovie, 5});

	const std::string precomputed =
		R"(<H1>Rentals for <EM>Jonathan</EM></H1><P>
Up: 3.000000<BR>
Blade Runner: 14.000000<BR>
The Lego Movie: 15.000000<BR>
<P>You owe <EM>32.000000</EM><P>
On this rental you earned <EM>4</EM> frequent renter points<P>)";

	checkSame(customer.htmlStatement(), precomputed);
}