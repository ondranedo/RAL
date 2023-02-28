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
"src/ral.cpp"
"src/ral.h")

#core files
"src/types.h"
"src/logger.h"
"src/logger.cpp"
 "src/defines.h"

install(TARGETS ral)