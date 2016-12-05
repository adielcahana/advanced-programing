
#include "gtest/gtest.h"
#include "Driver.h"

TEST(Trip, getNextPointTest){
    vector<Point*> route;
    Trip trip = Trip(1, Point(0,0), Point(2,2), 4, route);
    EXPECT_EQ(trip.getNextPoint(), Point(0,1));
    EXPECT_EQ(trip.getNextPoint(), Point(0,2));
    EXPECT_EQ(trip.getNextPoint(), Point(1,2));
    EXPECT_EQ(trip.getNextPoint(), Point(2,2));
}

TEST(Trip, getPriceTest){
    vector<Point*> route;
    Trip trip = Trip(1, Point(0,0), Point(1,1), 4, route);
    //trip start with price = 0
    EXPECT_EQ(0, trip.getPrice());
}

TEST(Trip, setPriceTest){
    vector<Point*> route;
    Trip trip = Trip(1, Point(0,0), Point(5,5), 4, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    for(int i = 0; i < 10; i++) {
        driver.moveOneStep();
        float newPrice = trip.getPrice() + driver.getTaxi().getTariff();
        trip.setPrice(newPrice);
        EXPECT_EQ(trip.getPrice(), newPrice);
    }
}