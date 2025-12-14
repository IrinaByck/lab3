cmake_minimum_required(VERSION 3.10)

project(lab_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_03
    src/main.cpp
    src/Figure.cpp
    src/Square.cpp
    src/Rectangle.cpp
    src/Trapezoid.cpp
)

target_include_directories(lab_03 PRIVATE include)

find_package(GTest)

if(GTest_FOUND)
    add_executable(tests
        tests/test_figures.cpp
        src/Figure.cpp
        src/Square.cpp
        src/Rectangle.cpp
        src/Trapezoid.cpp
    )
    
    target_include_directories(tests PRIVATE include)
    
    target_link_libraries(tests GTest::gtest GTest::gtest_main)
endif()
