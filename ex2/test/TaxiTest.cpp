#include "gtest/gtest.h"
#include "../src/Taxi.h"

TEST(Taxi, getTariffTest){
    float tariff;
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        Taxi taxi(1, HONDA, RED, tariff, Point(0,0));
        EXPECT_EQ(tariff, taxi.getTariff());
    }
}

TEST(Taxi, setTariffTest) {
    float tariff = 0;
    Taxi taxi(1, HONDA, RED, tariff, Point(0,0));
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        taxi.setTariff(tariff);
        ASSERT_EQ(tariff, taxi.getTariff());
    }
}

TEST(Taxi, getLocationTest) {
    for (int i = 0; i < 10; i++) {
        Point location = Point((rand() % 3), (rand() % 3));
        Taxi taxi(1, HONDA, RED, 1, location);
        taxi.updateLocation(location);
        EXPECT_EQ(location, taxi.getLocation());
    }
}

TEST(Taxi, updateLocationTest) {
    Point location = Point(0,0);
    Taxi taxi(1, HONDA, RED, 1, location);
    for (int i = 0; i < 10; i++) {
        location = Point((rand() % 3), (rand() % 3));
        taxi.updateLocation(location);
        ASSERT_EQ(location, taxi.getLocation());
    }
}

TEST(Taxi, moveOneStepTest){
    Taxi taxi(1, HONDA, RED, 1, Point(0,0));
    Point location = taxi.getLocation();
    Point nextLocation(location.getX(), location.getY() + 1);
    taxi.moveOneStep(nextLocation);
    EXPECT_EQ(taxi.getLocation(), nextLocation);
    //try to move more then 1 cell
    nextLocation= Point(location.getX() + 2, location.getY() + 2);
    EXPECT_THROW(taxi.moveOneStep(nextLocation), exception);
    //test for out of map next location in driver test
}

TEST(Taxi, getKmTest){
    Taxi taxi(1, HONDA, RED, 1, Point(0,0));
    float km = taxi.getKm();
    EXPECT_EQ(0, km);
}