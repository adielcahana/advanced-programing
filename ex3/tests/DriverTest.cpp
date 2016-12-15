#include <gtest/gtest.h>
#include "../src/TaxiCenter.h"

/******************************************************************************
* TripTest: source file that test the Driver class.
******************************************************************************/

TEST(Driver, getTaxiTest){
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    EXPECT_EQ(*taxi, *driver->getTaxi());
    delete taxiCenter;
}

TEST(Driver, setTaxiTest) {
    Taxi* taxi = new Taxi(1, HONDA, RED);
    Driver* driver = new Driver(5, 30, SINGLE, 6, 0);
    driver->setTaxi(taxi);
    EXPECT_EQ(taxi, driver->getTaxi());
}

TEST(Driver, getTaxiIdTest) {
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(5, 30, SINGLE, 6, 0);
    driver->setTaxi(taxi);
    EXPECT_EQ(0, driver->getTaxiId());
}

TEST(Driver, getIdTest) {
    Driver* driver = new Driver(0, 30, SINGLE, 6, 0);
    EXPECT_EQ(0, driver->getId());
}

TEST(Driver, getLocationTest) {
    Driver* driver = new Driver(5, 30, SINGLE, 6, 0);
    EXPECT_EQ(Point(0,0), *driver->getLocation());
}

/******************************************************************************
* The Test Operation: set new trip and check if he have trip
******************************************************************************/
TEST(Driver, newTripTest){
    Driver* driver = new Driver(5, 30, SINGLE, 6, 0);
    Point start(0, 0);
    Point end(0, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    driver->newTrip(trip);
    EXPECT_FALSE(driver->isAvaliable());
}

/******************************************************************************
* The Test Operation: set trip to the driver and check if he is avaliable
******************************************************************************/
TEST(Driver, isAvaliableTest){
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(0, 40, SINGLE, 6, 0);
    EXPECT_TRUE(driver->isAvaliable());
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(0, 2);
    Trip *trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    EXPECT_FALSE(driver->isAvaliable());
    delete map;
    delete taxiCenter;
}

TEST(Driver, timePassedTest) {
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(0, 2);
    Trip *trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    for (int i = 0; i < 2; i++) {
        driver->timePassed();
        EXPECT_EQ(Point(0,i), *driver->getLocation());
    }
    delete map;
    delete taxiCenter;
}

/******************************************************************************
* The Test Operation: check if the driver change his location after
* move one step
******************************************************************************/
TEST(Driver, moveOneStepTest) {
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start(0, 0);
    Point end(0, 2);
    Trip *trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    for (int i = 0; i < 2; i++) {
        driver->moveOneStep();
        EXPECT_EQ(Point(0,i), *driver->getLocation());
    }
    delete map;
    delete taxiCenter;
}
