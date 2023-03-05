
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	add_compile_definitions(RAL_DEBUG)
endif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

if(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
add_compile_definitions(RAL_RELEASE)
endif(${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")

#add_compile_definitions(RAL_EXPORT) #for shared only

set(SUBDIRS 
"src/core" 
"src/tests" 
"src/containers")

add_library(ral)
foreach(SUBDIR ${SUBDIRS})
    add_subdirectory(${SUBDIR})
    file(GLOB SUBDIR_SOURCES ${SUBDIR}/*.cpp)
    target_sources(ral PRIVATE ${SUBDIR_SOURCES})
endforeach()

target_include_directories(ral PUBLIC "${PROJECT_SOURCE_DIR}/RAL/src")

install(TARGETS ral DESTINATION ${CMAKE_INSTALL_PREFIX})

