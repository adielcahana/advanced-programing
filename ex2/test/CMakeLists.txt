project(tests)

set(SOURCE_FILES TaxiTest.cpp DriverTest.cpp TripTest.cpp LuxTaxiTest.cpp DriverInfoTest.cpp TaxiCenterTest.cpp SpriteCollectionTest.cpp SpriteCollectionTest.h)

add_executable(runTest ${SOURCE_FILES})

add_subdirectory(googletest)

target_link_libraries(runTest gtest gtest_main)
target_link_libraries(runTest src)