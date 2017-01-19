# Copyright (c) 2016-2017, Cédric Charière Fiedler
# All rights reserved.
cmake_minimum_required(VERSION 3.1)
project(cpp-seed)

#------------------------------
# Flag definition
#------------------------------

set (CMAKE_CXX_STANDARD 14)

#------------------------------
# Hunter package manager
#------------------------------

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.17.3.tar.gz"
    SHA1 "2a2f193860e2cb3b884bce74d85c3f30b1092274"
)

#-------------------------------
# Packages dependencies
#-------------------------------
hunter_add_package(SDL2)
find_package(SDL2 CONFIG REQUIRED)


#-------------------------------
# Include and files
#-------------------------------

INCLUDE_DIRECTORIES(         
	include
)

file(         
	GLOB_RECURSE
        SOURCE_FILES         
	src
)


#-------------------------------
# Executable
#-------------------------------

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")     
	set(ADDITIONAL_LIBS "mingw32") 
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES}  src/main.cpp) 
target_link_libraries(${PROJECT_NAME}  SDL2::SDL2)
