cmake_minimum_required(VERSION 3.7)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)


project(cpp-seed CXX)

include(CTest)
include(Coverage)

if(COVERAGE_SUPPORTED AND CMAKE_CONFIGURATION_TYPES)
    # Modify this only if using a multi-config generator, some modules rely on this variable to detect those generators.
    list(APPEND CMAKE_CONFIGURATION_TYPES "Coverage")
endif()

# ------------------------------------------------------
# Options
# ------------------------------------------------------
option(ENABLE_DOC "Allow the doc generation" OFF)
option(ENABLE_TEST "Allow the unit testing" ON)
option(ENABLE_COVERAGE "Allow the unit testing coverage" ON)

# ------------------------------------------------------

# ------------------------------------------------------
# External Dependencies
# ------------------------------------------------------
include(ExternalProject)

if (ENABLE_TEST)
    # Catch - a test lib
    ExternalProject_Add(
        catch-install
        GIT_REPOSITORY https://github.com/philsquared/Catch.git
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/external/
    )
endif(ENABLE_TEST)

add_library(Catch INTERFACE)
ADD_DEPENDENCIES(Catch catch-install)
target_include_directories(Catch INTERFACE CATCH_INCLUDE_DIR external/include/catch)


# SPDLog - a logging lib
ExternalProject_Add(# ------------------------------------------------------
    spdlog-install
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/external/
)


add_library(spdlog INTERFACE)
ADD_DEPENDENCIES(spdlog spdlog-install)
target_include_directories(spdlog INTERFACE SPDLOG_INCLUDE_DIR external/include/spdlog)


add_subdirectory(modules)

