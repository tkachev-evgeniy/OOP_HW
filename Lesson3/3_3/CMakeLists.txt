cmake_minimum_required(VERSION 3.5)

project(3_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set (sources
    main.cpp
    fraction.cpp
    )

add_executable(3_3 ${sources})

target_include_directories(3_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
