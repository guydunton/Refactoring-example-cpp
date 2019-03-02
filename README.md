# Refactoring Example C++

This is a worked through example from Martin Fowler's great book on [Refactoring](https://martinfowler.com/books/refactoring.html).

As I've gone through the example from the start of the book I've tried to make small changes and add git tags. Each tag represents a part of the example where a single refactoring or change has been made.

## Tag list

This is a list of all the tags with messages.

| Tag  | Message                                                                   |
| ---- | ------------------------------------------------------------------------- |
| v1.0 | Basic unchanged example                                                   |
| v1.1 | Added unit tests                                                          |
| v1.2 | Extracted Customer::amountFor from Customer::statement                    |
| v1.3 | Moved Customer::amountFor to Rental::getCharge                            |
| v1.4 | Refactored away temporary amount variable in favour of queries            |
| v1.5 | Extracted frequentRenterPoints into method in Rental                      |
| v1.6 | Extracted totalAmount and frequentRenterPoints                            |
| v1.7 | Added html statement                                                      |
| v1.8 | Moved get charge into movie                                               |
| v1.9 | Moved frequent renter points calculation to movie                         |
| v2.0 | Step 0 of replacing the Movie price codes with a polymorphic class        |
| v2.1 | Self encapsulate priceCode field                                          |
| v2.2 | Replaced type code with state                                             |
| v2.3 | Move Method getCharge from Movie into Price                               |
| v2.4 | Replaced Conditional with polymorphism for Price::getCharge               |
| v2.5 | Moved method getFrequentRenterPoints from Movie to Price                  |
| v2.6 | Replaced condition with polymorphic behaviour for getFrequentRenterPoints |

## Building the project
The project is self contained and should build on any C++14 compliant compiler and uses CMake as it's build tool.

To build:

```
git clone https://github.com/guydunton/Refactoring-example-cpp.git
cd Refactoring-example-cpp
mkdir build
cd build
cmake ..
cmake --build .
ctest --output-on-failure
```
