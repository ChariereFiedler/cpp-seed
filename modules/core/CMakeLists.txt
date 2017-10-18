set(MODULE_NAME ${CMAKE_PROJECT_NAME}-core)

add_subdirectory(test)

add_library(
    ${MODULE_NAME}-library
    source/foo.cpp)

target_include_directories(
    ${MODULE_NAME}-library
    PUBLIC include)

add_executable(
    ${MODULE_NAME}-sample
    sample/my-project.cpp
)

target_include_directories(
    ${MODULE_NAME}-library
    PRIVATE include
)
