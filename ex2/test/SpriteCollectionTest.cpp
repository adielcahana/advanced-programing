#include "../SpriteCollection.h"
#include "../TaxiCenter.h"
#include "gtest/gtest.h"

TEST(SpriteCollectionTest, addSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    EXPECT_NO_THROW(sp.removeSprite(driver));
    delete driver;
}

TEST(SpriteCollectionTest, removeSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    sp.removeSprite(driver);
    EXPECT_THROW(sp.removeSprite(driver), exception);
    delete driver;
}

TEST(SpriteCollectionTest, notifyAllTimePassedTest) {
    SpriteCollection sp;
    vector <Passenger> pass;
    Map *map = new Map(10, 10);
    vector<Point *> route;
    for (int i = 0; i < 2; i++) {
        route.push_back(new Point(0, i));
    }
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver *driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver->newTrip(trip);
    sp.addSprite(driver);
    EXPECT_EQ(driver->getLocation(), Point(0,0));
    for (int i = 0; i < 2; i++) {
        EXPECT_FALSE(driver->isAvaliable());
        sp.notifyAllTimePassed();
        EXPECT_EQ(driver->getLocation(), Point(0,i));
    }
    EXPECT_TRUE(driver->isAvaliable());
    for (int i = 0; i < 2; i++) {
        delete route.at(i);
    }
    delete map;
    delete driver;
}