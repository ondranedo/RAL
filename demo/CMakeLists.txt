add_executable(demo "src/demo.cpp")

target_include_directories(demo PUBLIC "${PROJECT_SOURCE_DIR}/RAL/include")

target_link_libraries(demo ral)




