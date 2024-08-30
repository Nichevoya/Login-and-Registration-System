# ------------------------------ configuration ----------------------------- 

cmake_minimum_required(VERSION 3.27.7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/.cmake/dependencies/")

project("LARS" VERSION 1.0.1 LANGUAGES CXX)

# ------------------------------ dependencies ------------------------------ 

find_package(Phoenix REQUIRED)
find_package(Cxxopts REQUIRED)
find_package(Catch2 REQUIRED)

# ----------------------------- custom settings ---------------------------- 

include("${CMAKE_SOURCE_DIR}/.cmake/configurations/build.cmake")

# --------------------------------- sources -------------------------------- 
add_subdirectory("./source/")

# ---------------------------------- tests --------------------------------- 
add_subdirectory("./tests/")
