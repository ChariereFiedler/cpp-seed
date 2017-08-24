cmake_minimum_required(VERSION 3.8)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)


project(cpp-seed CXX)



include(Coverage)


if(COVERAGE_SUPPORTED AND CMAKE_CONFIGURATION_TYPES)
    # Modify this only if using a multi-config generator, some modules rely on this variable to detect those generators.
    list(APPEND CMAKE_CONFIGURATION_TYPES "Coverage")
endif()

# ------------------------------------------------------
# Options
# ------------------------------------------------------
option(ENABLE_DOC "Allow the doc generation" ON)
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
        EXCLUDE_FROM_ALL TRUE
    )
endif(ENABLE_TEST)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/include/catch)


# SPDLog - a logging lib
ExternalProject_Add(# ------------------------------------------------------
    spdlog-install
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_SOURCE_DIR}/external/
    EXCLUDE_FROM_ALL TRUE
)


add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE SPDLOG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/include/spdlog)


# Install step
if (ENABLE_TEST)
    add_custom_target(
            install-all
            DEPENDS catch-install spdlog-install
    )
else()
    add_custom_target(
            install-all
            DEPENDS spdlog-install
    )
endif()

add_subdirectory(modules)

