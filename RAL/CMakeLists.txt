#######################################################
# Copyright (C) 2023                                  #
# Ondřej Nedojedlý (https://www.github.com/ondranedo),#
# Matyáš Noska (https://www.github.com/sutiama),      #
# Vojtěch Šokala (https://github.com/Karnatour),      #
# Adam Wiszczor (https://github.com/1nome).           #
#                                                     #
# This file is part of `RAL_PROJECT` project          #
# which is released under `GNU General Public         #
# License v3.0` license.                              #
# See file `LICENSE` for full license details.        #
#######################################################

#######################################################
#   Cmake for entire RAL engine                       #
#######################################################
# this CMakeLists is used to link vendor libraries and build the engine
# and set build definitions that alter engine behavior.
#   Build the include files and source files into the engine library.

#######################################################
#   engine general options                            #
#######################################################
include_directories(${PROJECT_SOURCE_DIR}/RAL)

project(RAL VERSION 0.0.1)
set(RAL_ENGINE_LIB ral-engine)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#######################################################
#   engine defines                                    #
#######################################################
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_compile_definitions(RAL_DEBUG)
endif()

if(WIN32)
    add_compile_definitions(RAL_WINDOWS)
endif()

#######################################################
#   Source files  - components                        #
#######################################################

add_library(${RAL_ENGINE_LIB} STATIC
        "RAL.cpp"
        "RAL.h")

# Engines core - main library others libraries link into this one
add_subdirectory(core)

# Platform layer - contains platform specific code
add_subdirectory(platfomLayer)

# Renderer - contains renderer specific code
add_subdirectory(renderer)

target_link_libraries(${RAL_ENGINE_LIB} PRIVATE ral_renderer)
target_link_libraries(${RAL_ENGINE_LIB} PRIVATE ral_core)
target_link_libraries(${RAL_ENGINE_LIB} PRIVATE ral_platformLayer)

#######################################################
#   Vendor libraries                                  #
#######################################################

#GLFW
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glfw)
target_link_libraries(${RAL_ENGINE_LIB} PRIVATE glfw)

#GLAD
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glad)
target_link_libraries(${RAL_ENGINE_LIB} PRIVATE glad)
target_link_libraries(${RAL_ENGINE_LIB} PRIVATE opengl32)