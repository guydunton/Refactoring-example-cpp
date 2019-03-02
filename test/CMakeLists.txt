project(RefactoringTests)

add_executable(RefactoringTests
    catch.hpp
	main.cpp
	statement-test.cpp
	html-statement.cpp
	string-manipulation.cpp
	string-manipulation.hpp
	check-same.hpp
)

target_link_libraries(RefactoringTests
    PUBLIC
        RefactoringLib
)

target_compile_features(RefactoringTests
    PUBLIC
        cxx_std_14
)

add_test(Test RefactoringTests)