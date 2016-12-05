
#include "gtest/gtest.h"
#include "../DriverInfo.h"

TEST(DriverInfo, getLocationTest){
    vector<Point*> route;
    Trip trip = Trip(1, Point(0,0), Point(1,1), 4, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0, 0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10, 10));
    DriverInfo driverInfo = DriverInfo(driver, taxi,Point(0,0), trip);
    EXPECT_EQ(Point(0,0), driverInfo.getLocation());
}