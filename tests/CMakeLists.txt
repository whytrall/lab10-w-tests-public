project(${CMAKE_PROJECT_NAME}_tests)

# Clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/lib/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
        find_package(Git REQUIRED)
        execute_process(
                COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
        )
endif()

add_subdirectory(lib/googletest)
add_subdirectory(unit_tests)

enable_testing()

set(test_SRCS
        unit_tests/assign.cpp
        unit_tests/constructors.cpp
        unit_tests/deletion.cpp
        unit_tests/empty_size.cpp
        unit_tests/find.cpp
        unit_tests/insertion.cpp
        unit_tests/iterators.cpp
        unit_tests/custom_comparator.cpp)

add_executable(Tests_run main.cpp ${test_SRCS})
target_link_libraries(Tests_run gtest gtest_main)
target_link_libraries(Tests_run ${CMAKE_PROJECT_NAME}_lib)
add_test(Tests Tests_run)
