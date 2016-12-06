#include <gtest/gtest.h>
#include "../Driver.h"

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
    EXPECT_TRUE(driver.isAvaliable());
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvaliable());
}

TEST(Driver, newTripTest){
    vector<Point*> route;
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver.newTrip(trip);
    EXPECT_FALSE(driver.isAvaliable());
}

TEST(Driver, getPaymentTest){
    float price;
    vector<Point*> route;
    for(int i = 0; i < 5; i++){
        route.push_back(new Point(0,i));
    }
    for(int i = 0; i < 5; i++){
        route.push_back(new Point(i,5));
    }
    vector <Passenger> pass;
    Trip trip = Trip(1, Point(0, 0), Point(5, 5), 4, route, pass, 0);
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
    vector<Point*> route;
    vector <Passenger> pass;
    PointComparator cmp;
    for (int i = 0; i < 5; i++) {
        route.push_back(new Point(0, i));
    }
    for (int i = 0; i < 5; i++) {
        route.push_back(new Point(i, 4));
    }
    Trip trip = Trip(1, Point(0, 0), Point(1, 1), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(5, 5));
    for (int i = 0; i < 10; i++) {
        EXPECT_FALSE(driver.isAvaliable());
        driver.moveOneStep();
        Point p = driver.getTaxi().getLocation();
        EXPECT_TRUE(cmp.equals(&p, route.at(i)));
        EXPECT_EQ(driver.getPayment(), driver.getTaxi().getTariff() * i);
    }
    // move after the trip over
    EXPECT_TRUE(driver.isAvaliable());
    EXPECT_THROW(driver.moveOneStep(), exception);
    for(int i = 0; i < 10; i++){
        delete route.at(i);
    }
    route.clear();
}

TEST(Driver, getSatisfacation){
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    vector <Passenger> pass;
    Passenger passenger(Point (0,0), Point(1,1));
    pass.push_back(passenger);
    vector<Point*> route;
    route.push_back(new Point(0,1));
    Trip trip = Trip(1, Point(0, 0), Point(0, 1), 1, route, pass, 0);
    Driver driver = Driver(5, 25, SINGLE, 5, taxi, Map(10, 10));
    driver.moveOneStep();
    EXPECT_EQ(driver.getSatisfacation(), passenger.satisfacation());
}