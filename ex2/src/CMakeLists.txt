cmake_minimum_required(VERSION 3.6)
project(Ass2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp Flow.cpp Flow.h Sprite.cpp Sprite.h SpriteCollection.cpp SpriteCollection.h Driver.cpp Driver.h DriverInfo.cpp DriverInfo.h Taxi.cpp Taxi.h Trip.cpp Trip.h Passenger.cpp Passenger.h TaxiCenter.cpp TaxiCenter.h LuxTaxi.cpp LuxTaxi.h)
add_executable(Ass2 ${SOURCE_FILES})