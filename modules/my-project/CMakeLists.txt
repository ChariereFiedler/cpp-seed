project(my-project C CXX)


add_subdirectory(test)

add_library(
    my-project-library
        source/foo.cpp)

target_include_directories(
    my-project-library
    PUBLIC include)

add_executable(
    my-project
        sample/my-project.cpp
)

target_include_directories(
        my-project-library
        PRIVATE include)

# --------------------------------------------------
# Doxygen Section
# --------------------------------------------------
if(ENABLE_DOC)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN doc/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

        add_custom_target(
                my-project_doc_doxygen
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                VERBATIM
        )

    else(DOXYGEN_FOUND)
        message(FATAL_ERROR "Please install Doxygen to create the documentation")
    endif(DOXYGEN_FOUND)
endif(ENABLE_DOC)
# / Doxygen Section
# --------------------------------------------------
