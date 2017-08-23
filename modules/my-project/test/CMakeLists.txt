cmake_minimum_required(VERSION 3.6)


add_executable(
        MY-P.foo-test
        foo-test.cpp
)

target_link_libraries(
        MY-P.foo-test
        my-project-library
        Catch
)

target_include_directories(
        MY-P.foo-test
        PUBLIC ../include)

add_test(
    # Use some per-module/project prefix so that it is easier to run only tests for this module
    NAME MY-P.foo-test
    COMMAND MY-P.foo-test
)
