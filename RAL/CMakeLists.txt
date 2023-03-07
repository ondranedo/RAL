set(file_containers            src/containers/string.cpp src/containers/string.h)
set(file_core                  src/core/application.cpp src/core/application.h src/core/baseGame.cpp src/core/defines.h src/core/logger.cpp src/core/main.cpp)
set(file_platformLayer_memory  src/platformLayer/memory/memory.cpp src/platformLayer/memory/memory.h)
set(file_platformLayer_console src/platformLayer/console/console.cpp src/platformLayer/console/console.h src/platformLayer/console/wConsole.cpp src/platformLayer/console/wConsole.h)
set(file_test                  src/tests/test.cpp src/tests/test.h)

set(src ${file_containers} ${file_core} ${file_platformLayer_memory} ${file_platformLayer_console} ${file_test} src/pch.h)

add_library(ral ${src})

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