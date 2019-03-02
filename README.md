# Refactoring Example C++

This is a worked through example from Martin Fowler's great book on [Refactoring](https://martinfowler.com/books/refactoring.html).

As I've gone through the example from the start of the book I've tried to make small changes and add git tags. Each tag represents a part of the example where a single refactoring or change has been made.

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