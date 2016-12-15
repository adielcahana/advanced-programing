#include "gtest/gtest.h"
#include "../src/Driver.h"
#include "../src/TaxiCenter.h"

/******************************************************************************
* TripTest: source file that test the Trip class.
******************************************************************************/

/******************************************************************************
* The Test Operation: check the next point in the trip
******************************************************************************/
TEST(Trip, getNextPointTest){
    Map* map = new Map(3,3);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(2, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    for(int i = 0; i <= 2; i++){
        EXPECT_EQ(Point(0,i), *trip->getNextPoint());
    }
    for(int j = 1; j <= 2; j++){
        EXPECT_EQ( Point(j,2), *trip->getNextPoint());
    }
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: create a trip with price 5 and compare to getPrice
******************************************************************************/
TEST(Trip, getPriceTest){
    float price = 5;
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, 2, price);
    EXPECT_FLOAT_EQ(5, trip->getPrice());
}

TEST(Trip, getNumPassengersTest){
    int passengers = 2;
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, passengers, 1);
    EXPECT_EQ(2, trip->getNumPassengers());
}

TEST(Trip, sumOfSatisfactionTest){
    int passengers = 2;
    Point start(0, 0);
    Point end(0, 1);
    Trip* trip = new Trip(0, start, end, passengers, 1);
    EXPECT_LE(2, trip->sumOfSatisfaction());
    EXPECT_GE(10, trip->sumOfSatisfaction());
}