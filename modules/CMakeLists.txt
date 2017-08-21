# Include modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake/modules)


# ----------------------------------------------
# Submodule inclusion
# ----------------------------------------------
# Add explicitly each submodule
add_subdirectory(my-project)

# ...

# ----------------------------------------------
# Doc inclusion
# ----------------------------------------------
add_custom_target(
        all_doc_doxygen
        DEPENDS
            my-project_doc_doxygen
)