cmake_minimum_required(VERSION 3.6)

list(APPEND TO_TEST
    foo-test.cpp
)

FOREACH(item ${TO_TEST})

    get_filename_component(item_name ${item} NAME_WE)


    add_executable(
            ${MODULE_NAME}-test.${item_name}
            ${item}
    )

    target_link_libraries(
            ${MODULE_NAME}-test.${item_name}
            ${MODULE_NAME}-library
            Catch
    )

    target_include_directories(
            ${MODULE_NAME}-test.${item_name}
            PUBLIC ../include)

    add_test(
        # Use some per-module/project prefix so that it is easier to run only tests for this module
        NAME ${MODULE_NAME}-test.${item_name}
        COMMAND ${MODULE_NAME}-test.${item_name}
    )
endforeach()