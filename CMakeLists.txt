cmake_minimum_required(VERSION 3.1)

project(cpp-seed CXX)



set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Options
option(ENABLE_DOC "Allow the doc generation" ON)

add_subdirectory(modules)