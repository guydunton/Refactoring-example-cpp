project(RefactoringLib)

add_library(RefactoringLib STATIC
    movie.cpp
    movie.hpp
    rental.hpp
    rental.cpp
    customer.hpp
    customer.cpp
)

target_include_directories(RefactoringLib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(RefactoringLib
    PUBLIC
        cxx_std_17
)