cmake_minimum_required(VERSION 3.30.0)
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cpp")

foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    message(STATUS "Adding test: ${test_name}")
    add_executable(${test_name} EXCLUDE_FROM_ALL ${test_source})
    target_link_libraries(${test_name} coshd Catch2::Catch2WithMain fakeit::fakeit fmt::fmt)
    set_target_properties(${test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test
        COMMAND ${test_name})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()