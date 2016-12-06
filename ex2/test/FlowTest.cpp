#include "gtest/gtest.h"
#include "../Flow.h"
#include "../DriverInfo.h"

TEST(Flow, initilizeTest){
    SpriteCollection sp;
    Flow flow = Flow(sp);
    flow.initilize();
    EXPECT_NO_THROW("Somthing wrong");
}

TEST(Flow, runTest){
    SpriteCollection sp;
    Flow flow = Flow(sp);
    flow.run();
    EXPECT_NO_THROW("Somthing wrong");
}

TEST(Flow, notifyTimePassedTest){
    SpriteCollection sp;
    vector <Passenger> pass;
    Map *map = new Map(10, 10);
    vector<Point *> route;
    for (int i = 0; i < 2; i++) {
        route.push_back(new Point(0, i));
    }
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass, 0);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver *driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));Flow flow = Flow(sp);
    driver->newTrip(trip);
    sp.addSprite(driver);
    EXPECT_EQ(driver->getLocation(), Point(0,0));
    for (int i = 0; i < 2; i++) {
        flow.notifyTimePassed();
        EXPECT_EQ(driver->getLocation(), Point(0,i));
    }
    EXPECT_TRUE(driver->isAvaliable());
    for (int i = 0; i < 2; i++) {
        delete route.at(i);
    }
    delete map;
    delete driver;
}