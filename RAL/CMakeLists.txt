set(file_containers            src/containers/string.cpp src/containers/string.h)
set(file_core                  src/core/application.cpp src/core/application.h src/core/baseGame.cpp src/core/defines.h src/core/logger.cpp src/core/main.cpp)
set(file_platformLayer_memory  src/platformLayer/memory/memory.cpp src/platformLayer/memory/memory.h)
set(file_platformLayer_console src/platformLayer/console/consoleInterpreter.cpp src/platformLayer/console/consoleInterpreter.h src/platformLayer/console/wConsoleInterpreter.cpp src/platformLayer/console/wConsoleInterpreter.h)
set(file_platformLayer_window  src/platformLayer/window/window.cpp src/platformLayer/window/windowFactory.cpp src/platformLayer/window/WindowsWindow.cpp)
set(file_test                  src/tests/test.cpp src/tests/test.h)

set(src ${file_containers} ${file_core} ${file_platformLayer_memory} ${file_platformLayer_console} ${file_test} src/pch.h ${file_platformLayer_window})

add_library(ral ${src})

########################################################################################################################

target_include_directories(ral PRIVATE "${CMAKE_SOURCE_DIR}/RAL/vendor/glfw/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/RAL/vendor/glfw")
target_link_libraries(ral glfw)

########################################################################################################################

if(WIN32)
    target_compile_definitions(ral PUBLIC RAL_WINDOWS)
endif(WIN32)

if(UNIX AND NOT APPLE)
    target_compile_definitions(ral PUBLIC RAL_LINUX)
endif(UNIX AND NOT APPLE)

if(UNIX)
    target_compile_definitions(ral PUBLIC RAL_APPLE)
endif(UNIX)

if(CMAKE_BUILD_TYPE  STREQUAL "Debug")
    target_compile_definitions(ral PUBLIC RAL_DEBUG)
endif(CMAKE_BUILD_TYPE  STREQUAL "Debug")

if(CMAKE_BUILD_TYPE  STREQUAL "RelWithDebInfo")
    target_compile_definitions(ral PUBLIC RAL_RELEASE)
endif(CMAKE_BUILD_TYPE  STREQUAL "RelWithDebInfo")

if(CMAKE_BUILD_TYPE  STREQUAL "MinSizeRel")
    target_compile_definitions(ral PUBLIC RAL_DISTRIBUTE)
endif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")