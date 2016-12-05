
#include "gtest/gtest.h"
#include "LuxTaxi.h"

TEST(LuxTaxi, setTariffTest) {
    float tariff = 0;
    LuxTaxi luxTaxi(1, HONDA, RED, tariff, Point(0,0));
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        luxTaxi.setTariff(tariff);
        ASSERT_EQ(tariff, luxTaxi.getTariff());
    }
}

TEST(LuxTaxi, moveOneStepTest){
    LuxTaxi luxTaxi(1, HONDA, RED, 1, Point(0,0));
    Point location = luxTaxi.getLocation();
    // move 1 cell
    Point nextLocation(location.getX(), location.getY() + 1);
    luxTaxi.moveOneStep(nextLocation);
    EXPECT_EQ(luxTaxi.getLocation(), nextLocation);
    // move 2 cells
    nextLocation = Point(location.getX() + 1, location.getY() + 1);
    luxTaxi.moveOneStep(nextLocation);
    EXPECT_EQ(luxTaxi.getLocation(), nextLocation);
    //try to move more then 2 cell
    nextLocation = Point(location.getX() + 2, location.getY() + 2);
    EXPECT_THROW(luxTaxi.moveOneStep(nextLocation), exception);
    //tests for out of map next location in driver tests
}
