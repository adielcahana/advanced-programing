cmake_minimum_required(VERSION 3.6)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Flow.cpp Flow.h Sprite.cpp Sprite.h
        SpriteCollection.cpp SpriteCollection.h Driver.cpp Driver.h
        DriverInfo.cpp DriverInfo.h Taxi.cpp Taxi.h Trip.cpp Trip.h
        Passenger.cpp Passenger.h TaxiCenter.cpp TaxiCenter.h
        LuxTaxi.cpp LuxTaxi.h Map.cpp Map.h Bfs.cpp Bfs.h TaxiTest.cpp DriverTest.cpp TripTest.cpp LuxTaxiTest.cpp
        DriverInfoTest.cpp TaxiCenterTest.cpp SpriteCollectionTest.cpp
        SpriteCollectionTest.h BfsTest.cpp BfsTest.h MapTest.cpp)

#set(TEST_FILES )

add_executable(ex2 ${SOURCE_FILES})

target_link_libraries(ex2 gtest gtest_main)

