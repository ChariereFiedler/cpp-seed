cmake_minimum_required(VERSION 3.1)

project(cpp-seed CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# ------------------------------------------------------
# External Dependencies
# ------------------------------------------------------


include(ExternalProject)

# Catch - a test lib
ExternalProject_Add(
    catch-install
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/external/
    EXCLUDE_FROM_ALL TRUE
)


add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/include/catch)


# SPDLog - a logging lib
ExternalProject_Add(
    spdlog-install
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/external/
    EXCLUDE_FROM_ALL TRUE
)


add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/include/spdlog)


# Install step

add_custom_target(
        install-all
        DEPENDS catch-install
        DEPENDS spdlog-install
)


# ------------------------------------------------------
# Options
# ------------------------------------------------------
option(ENABLE_DOC "Allow the doc generation" ON)



enable_testing()
# ------------------------------------------------------

add_subdirectory(modules)