if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	add_compile_definitions(RAL_DEBUG)
endif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

if(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
add_compile_definitions(RAL_RELEASE)
endif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")

add_compile_definitions(RAL_EXPORT)

add_library(ral SHARED
#main include file
"include/RAL/RAL.h"

#test files
"src/tests/test.cpp"
"src/tests/test.h"

#core files
"src/core/types.h"
"src/core/logger.h"
"src/core/logger.cpp"
"src/core/defines.h")

target_include_directories(ral PUBLIC "${PROJECT_SOURCE_DIR}/RAL/src")

install(TARGETS ral)

