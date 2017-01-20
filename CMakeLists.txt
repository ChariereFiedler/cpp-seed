# Copyright (c) 2016-2017, Cédric Charière Fiedler
# All rights reserved.
cmake_minimum_required(VERSION 3.1)

#------------------------------
# Flag definition
#------------------------------

project(cpp-seed CXX)

set (CMAKE_CXX_STANDARD 14)


#------------------------------
# Conan package manager
#------------------------------
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake) #Clion, with conanbuildinfo.cmake in build folder
	include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
else()
	include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Not CLion
endif()
conan_basic_setup()

#-------------------------------
# Include and files
#-------------------------------

INCLUDE_DIRECTORIES(         
	include
)

file(         
	GLOB_RECURSE
        SOURCE_FILES         
	src/*
)


#-------------------------------
# Executable
#-------------------------------

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")     
	set(ADDITIONAL_LIBS "mingw32") 
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES}  src/main.cpp include/engine.h include/properties.h)
target_link_libraries(${PROJECT_NAME}  ${CONAN_LIBS})
