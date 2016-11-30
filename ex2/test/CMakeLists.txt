project(tests)

set(SOURCE_FILES firstTest.cpp)

add_executable(runTest ${SOURCE_FILES})

add_subdirectory(googletest)

target_link_libraries(runTest gtest gtest_main)
target_link_libraries(runTest src)
