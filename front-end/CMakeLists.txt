project(RefactoringExample)

add_executable(RefactoringExample 
    main.cpp
)

target_link_libraries(RefactoringExample
    PUBLIC
        RefactoringLib
)

target_compile_features(RefactoringExample
    PUBLIC
        cxx_std_14
)