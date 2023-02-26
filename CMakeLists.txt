cmake_minimum_required(VERSION 3.20)
project(RAL_PROJECT VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	add_compile_definitions(RAL_DEBUG)
endif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

if(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
add_compile_definitions(RAL_RELEASE)
endif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")


add_subdirectory("RAL")
add_subdirectory("demo")