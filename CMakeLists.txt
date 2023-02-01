cmake_minimum_required(VERSION 3.18)

project(tabu_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Solution.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Exception.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Matrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/TabuSearch.h
    )

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TabuSearch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Solution.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )

add_executable(tabu_search ${SOURCES} ${HEADERS})