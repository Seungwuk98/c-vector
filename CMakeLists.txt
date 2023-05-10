cmake_minimum_required(VERSION 3.0.0)
project(vector VERSION 0.1.0)

set(CMAKE_C_STANDARD         11)
set(CMAKE_C_STANDAR_REQUIRED ON)
set(CMAKE_C_EXTENSIONS       OFF)
set(VECTOR_TEST VectorTest)
set(VECTOR_CAPACITY_TEST VectorCapacityTest)
set(VECTOR_LIBRARY vector)

include(CTest)
enable_testing()

add_library(${VECTOR_LIBRARY} STATIC vector.c)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
target_include_directories(${VECTOR_LIBRARY} PUBLIC
    "./")   
include(CPack)

add_subdirectory(test)