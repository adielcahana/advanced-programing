#include "gtest/gtest.h"
#include "../src/TaxiCenter.h"

/******************************************************************************
* TripTest: source file that test the TaxiCenter class.
******************************************************************************/

TEST(TaxiCenter, addDriverTest){
    Map* map = new Map(3,3,NULL);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addDriver(driver);
    EXPECT_EQ(Point(0,0), taxiCenter->getLocation(0));
    delete map;
    delete taxiCenter;
}


TEST(TaxiCenter, searchTaxiByIdTest){
    Map* map = new Map(3,3,NULL);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    EXPECT_TRUE(taxiCenter->searchTaxiById(0) == NULL);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    taxiCenter->addAvaliableTaxi(taxi);
    EXPECT_EQ(taxi, taxiCenter->searchTaxiById(0));
    delete taxiCenter;
    delete map;
}

TEST(TaxiCenter, addAvaliableTaxiTest){
    Map* map = new Map(3,3,NULL);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addAvaliableTaxi(taxi);
    EXPECT_EQ(taxi, taxiCenter->searchTaxiById(0));
    delete taxiCenter;
    delete map;
}


TEST(TaxiCenter, addTripTest){
    Map* map = new Map(2, 2, NULL);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    Taxi* taxi = new Taxi(0, HONDA, RED);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Trip* trip = new Trip(0, Point(0,0), Point(2,2), 2, 1);
    taxiCenter->addTrip(trip);
    EXPECT_TRUE(trip->getNextPoint() != NULL);
}

TEST(TaxiCenter, getLocationByIdTest) {
    Map* map = new Map(3,3,NULL);
    Driver* driver = new Driver(0, 40, SINGLE, 6, 0);
    TaxiCenter* taxiCenter = new TaxiCenter(map);
    taxiCenter->addDriver(driver);
    EXPECT_EQ(Point(0,0), taxiCenter->getLocation(5));
    delete map;
    delete taxiCenter;
}

TEST(TaxiCenter, timePassedTest) {
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Point start = Point(0, 0);
    Point end = Point(0, 2);
    Trip* trip = new Trip(0, start, end, 2, 1);
    taxiCenter->addTrip(trip);
    for (int i = 0; i < 2; i++) {
        taxiCenter->timePassed();
        EXPECT_EQ(Point(0,i), taxiCenter->getLocation(0));
    }
    delete map;
    delete taxiCenter;
}

TEST(TaxiCenter, shouldStopTest) {
    Map *map = new Map(2, 2, NULL);
    TaxiCenter *taxiCenter = new TaxiCenter(map);
    Taxi *taxi = new Taxi(0, HONDA, RED);
    Driver *driver = new Driver(5, 40, SINGLE, 6, 0);
    taxiCenter->addAvaliableTaxi(taxi);
    taxiCenter->addDriver(driver);
    Trip *trip = new Trip(0, Point(0, 0), Point(0, 2), 2, 1);
    taxiCenter->addTrip(trip);
    EXPECT_FALSE(taxiCenter->shouldStop());
    delete map;
    delete taxiCenter;
}