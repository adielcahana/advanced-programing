
#include "gtest/gtest.h"
#include "../src/Driver.h"

TEST(Driver, getAgeTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    for (int i = 0; i < 10; i++) {
        int age = (rand() % 30) + 20;
        Driver driver = Driver(5, age, SINGLE, 5, taxi, Map(10, 10));
        EXPECT_EQ(age, driver.getAge());
    }
}

    TEST(Driver, setAgeTest){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    int age = 20;
    Driver driver = Driver(5, age, SINGLE, 5, taxi, Map(10, 10));
        for (int i = 0; i < 10; i++) {
            age = (rand() % 30) + 20;
            driver.setAge(age);
            ASSERT_EQ(age, driver.getAge());
        }
}

TEST(Driver, getTaxiTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    EXPECT_EQ(taxi, driver.getTaxi());
}

TEST(Driver, getStatusTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    for (int i = 0; i < 4; i++) {
        Status status = Status (i);
        Driver driver = Driver(5, 20, status, 5, taxi, Map(10, 10));
        EXPECT_EQ(status, driver.getStatus());
    }
}

TEST(Driver, setStatusTest) {
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Status status = SINGLE;
    Driver driver = Driver(5, 20, status, 5, taxi, Map(10, 10));
    for (int i = 0; i < 4; i++) {
        status = Status (i);
        driver.setStatus(status);
        ASSERT_EQ(status, driver.getStatus());
    }
}

TEST(Driver, isAvaliableTest){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    // driver start with trip = null
    EXPECT_TRUE(driver.isAvalible());
    vector<Point> route;
    Trip trip = Trip(1, Point(0,0), Point(1,1), 4, route);
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvalible());
}

TEST(Driver, newTripTest){
    vector<Point> route;
    Trip trip = Trip(1, Point(0,0), Point(1,1), 4, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvalible());
}

TEST(Driver, getPaymentTest){
    float price;
    vector<Point> route;
    for(int i = 0; i < 5; i++){
        route.push_back(Point(0,i));
    }
    for(int i = 0; i < 5; i++){
        route.push_back(Point(i,5));
    }
    Trip trip = Trip(1, Point(0,0), Point(5,5), 4, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    price = price += driver.getTaxi().getTariff();
    for(int i = 0; i < 10; i++){
        driver.moveOneStep();
    }
    EXPECT_EQ(driver.getPayment(), price);
}

TEST(Driver, moveOneStepTest) {
    vector<Point> route;
    for (int i = 0; i < 5; i++) {
        route.push_back(Point(0, i));
    }
    for (int i = 0; i < 5; i++) {
        route.push_back(Point(i, 4));
    }
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(5, 5));
    for (int i = 0; i < 10; i++) {
        EXPECT_FALSE(driver.isAvalible());
        driver.moveOneStep();
        EXPECT_EQ(driver.getTaxi().getLocation(), route.at(i));
        EXPECT_EQ(driver.getPayment(), driver.getTaxi().getTariff() * i);
    }
    // move after the trip over
    EXPECT_TRUE(driver.isAvalible());
    EXPECT_THROW(driver.moveOneStep(), exception);
}