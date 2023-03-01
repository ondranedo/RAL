add_executable(demo "src/main.cpp")

target_include_directories(demo PUBLIC "${PROJECT_SOURCE_DIR}/RAL/include")

target_link_libraries(demo ral)

install(TARGETS demo DESTINATION ${CMAKE_INSTALL_PREFIX})