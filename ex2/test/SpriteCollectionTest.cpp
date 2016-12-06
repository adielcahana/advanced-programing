#include "../SpriteCollection.h"
#include "../TaxiCenter.h"
#include "gtest/gtest.h"
/******************************************************************************
* PassengerTest: source file that test the SpriteCollection class.
******************************************************************************/

/******************************************************************************
* The Test Operation: add a sprite to the spriteCollection and expect no throw
* when try to remove
******************************************************************************/
TEST(SpriteCollectionTest, addSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    EXPECT_NO_THROW(sp.removeSprite(driver));
    delete driver;
}

/******************************************************************************
* The Test Operation: expect to exception when try to remove from empty vector
******************************************************************************/
TEST(SpriteCollectionTest, removeSpriteClass){
    SpriteCollection sp;
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver* driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    sp.addSprite(driver);
    sp.removeSprite(driver);
    EXPECT_THROW(sp.removeSprite(driver), exception);
    delete driver;
}

/******************************************************************************
* The Test Operation: add driver with trip to the spriteCollection and check
* if he moves when notify timePessed
******************************************************************************/
TEST(SpriteCollectionTest, notifyAllTimePassedTest) {
    // create the route
    SpriteCollection sp;
    vector <Passenger> pass;
    Map *map = new Map(10, 10);
    vector<Point *> route;
    for (int i = 0; i < 2; i++) {
        route.push_back(new Point(0, i));
    }
    Trip trip = Trip(1, Point(0, 0), Point(2, 2), 4, route, pass, 0);
    // create the driver and trip
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver *driver = new Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    driver->newTrip(trip);
    // add the driver to the spriteCollection
    sp.addSprite(driver);
    EXPECT_EQ(driver->getLocation(), Point(0,0));
    for (int i = 0; i < 2; i++) {
        // check if the driver move when notify time passed
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