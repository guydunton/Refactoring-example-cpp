project(RefactoringTests)

add_executable(RefactoringTests
    catch.hpp
	main.cpp
)

target_link_libraries(RefactoringTests
    PUBLIC
        RefactoringLib
)

target_compile_features(RefactoringTests
    PUBLIC
        cxx_std_17
)
