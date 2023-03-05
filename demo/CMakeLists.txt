add_executable(demo "src/demo.cpp")

target_link_libraries(demo PRIVATE ral)

target_include_directories(demo PUBLIC "${PROJECT_SOURCE_DIR}/RAL/include")


install(TARGETS demo DESTINATION ${CMAKE_INSTALL_PREFIX})