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
    Map* map = new Map(2, 2, NULL);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Trip* trip = new Trip(0, Point(0,0), Point(2,2), 2, 1);
    taxiCenter->addTrip(trip);
    for(int i = 0; i < 2; i++){
        EXPECT_EQ(Point(0,i), trip->getNextPoint());
    }
    for(int j = 0; j < 2; j++){
        EXPECT_EQ( Point(j,2), trip->getNextPoint());
    }
    delete map;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: create a trip with price 5 and compare to getPrice
******************************************************************************/
TEST(Trip, getPriceTest){
    float price = 5;
    Trip trip = Trip(0, Point(0,0), Point(2,2), 2, price);
    EXPECT_FLOAT_EQ(5, trip.getPrice());
}

TEST(Trip, getNumPassengersTest){
    int passengers = 2;
    Trip trip = Trip(0, Point(0,0), Point(2,2), passengers, 5);
    EXPECT_EQ(2, trip.getNumPassengers());
}

TEST(Trip, sumOfSatisfactionTest){
    int passengers = 2;
    Trip* trip = new Trip(0, Point(0,0), Point(0,1), passengers, 1);
    EXPECT_LE(2, trip->sumOfSatisfaction());
    EXPECT_GE(10, trip->sumOfSatisfaction());
}