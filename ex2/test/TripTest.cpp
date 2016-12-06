#include "gtest/gtest.h"
#include "../Driver.h"

TEST(Trip, getNextPointTest){
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass, 0);
    EXPECT_EQ(trip.getNextPoint(), Point(0,1));
    EXPECT_EQ(trip.getNextPoint(), Point(0,2));
    EXPECT_EQ(trip.getNextPoint(), Point(1,2));
    EXPECT_EQ(trip.getNextPoint(), Point(2,2));
}

TEST(Trip, getPriceTest){
    vector<Point*> route;
    vector <Passenger> pass;
    float price = 5;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, price);
    EXPECT_FLOAT_EQ(5, trip.getPrice());
}

TEST(Trip, setPriceTest){
    vector<Point*> route;
    vector <Passenger> pass;
    float price;
    Trip trip = Trip(1, Point(0, 0), Point(5, 5), 4, route, pass, 0);
    for(int i = 0; i < 10; i++) {
        price = (rand() / RAND_MAX) + (rand() % 100);
        trip.setPrice(price);
        EXPECT_FLOAT_EQ(trip.getPrice(), price);
    }
}