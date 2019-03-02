#include "catch.hpp"
#include "check-same.hpp"
#include <customer.hpp>
#include <movie.hpp>
#include <rental.hpp>


TEST_CASE("Customer::statement produces a report for customer with no rentals")
{
	Customer customer1{ "Tom Smith" };

	const std::string precomputedStatement =
R"(Rental record for Tom Smith
Amount owed is 0.000000
You earned 0 frequent renter points)";

	checkSame(precomputedStatement, customer1.statement());
}

TEST_CASE("Customer::statement NEW_RELEASE films with 1 day rental doesn't get frequent renter point")
{
	Customer customer1{ "Jim" };
	const Movie film{ "Cars", Movie::NEW_RELEASE };
	customer1.addRental(Rental{ film, 1 });

	const std::string precomputed =
R"(Rental record for Jim
	Cars	3.000000
Amount owed is 3.000000
You earned 1 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}

TEST_CASE("Customer::statement NEW_RELEASE gets extra frequent renter points above 1 day")
{
	Customer customer1{ "Jack" };
	const Movie movie{ "IRobot", Movie::NEW_RELEASE };
	customer1.addRental(Rental{ movie, 2 });

	const std::string precomputed =
R"(Rental record for Jack
	IRobot	6.000000
Amount owed is 6.000000
You earned 2 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}

TEST_CASE("Customer::statement REGULAR films just cost 2 for 2 or less days")
{
	Customer customer1{ "Frank" };
	const Movie movie{ "Dirty Harry", Movie::REGULAR };

	SECTION("1 Day")
	{
		customer1.addRental(Rental{ movie, 1 });
	}

	SECTION("2 Days")
	{
		customer1.addRental(Rental{ movie, 2 });
	}

	const std::string precomputed =
R"(Rental record for Frank
	Dirty Harry	2.000000
Amount owed is 2.000000
You earned 1 frequent renter points)";

	checkSame(precomputed, customer1.statement());	
}

TEST_CASE("Customer::statement REGULAR films cost more above 2 days")
{
	Customer customer1{ "Rebecca" };
	const Movie movie{ "Kill Bill", Movie::REGULAR };
	customer1.addRental(Rental{ movie, 3 });

	const std::string precomputed =
R"(Rental record for Rebecca
	Kill Bill	3.500000
Amount owed is 3.500000
You earned 1 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}

TEST_CASE("Customer::statement CHILDREN films are 1.5 for 3 or less days")
{
	Customer customer1{ "Gemma" };
	const Movie movie{ "Watership Down", Movie::CHILDREN };

	SECTION("1 Day")
	{
		customer1.addRental(Rental{ movie, 1 });
	}

	SECTION("2 Days")
	{
		customer1.addRental(Rental{ movie, 2 });
	}

	SECTION("3 Days")
	{
		customer1.addRental(Rental{ movie, 3 });
	}
	
	const std::string precomputed =
R"(Rental record for Gemma
	Watership Down	1.500000
Amount owed is 1.500000
You earned 1 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}

TEST_CASE("Customer::statement CHILDREN films cost more for each day above 3 days")
{
	Customer customer1{ "Charlotte" };
	const Movie movie{ "Matilda", Movie::CHILDREN };

	customer1.addRental(Rental{ movie, 6 });

	const std::string precomputed =
R"(Rental record for Charlotte
	Matilda	6.000000
Amount owed is 6.000000
You earned 1 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}

TEST_CASE("Customer::statement the cost of multiple films are added together")
{
	Customer customer1{ "Erika" };
	const Movie sleepyHollow{ "Sleepy Hollow", Movie::REGULAR };
	const Movie toyStory{ "Toy Story", Movie::CHILDREN };

	customer1.addRental(Rental{ sleepyHollow, 10 }); // Cost: 14
	customer1.addRental(Rental{ toyStory, 15 }); // Cost: 19.5

	const std::string precomputed =
R"(Rental record for Erika
	Sleepy Hollow	14.000000
	Toy Story	19.500000
Amount owed is 33.500000
You earned 2 frequent renter points)";

	checkSame(precomputed, customer1.statement());
}