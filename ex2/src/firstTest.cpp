
#include "gtest/gtest.h"
#include "../src/Taxi.h"


TEST(Taxi, getTariffTest){
    float tariff;
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        Taxi taxi(1, HONDA, RED, tariff);
        EXPECT_EQ(tariff, taxi.getTariff());
    }
}

TEST(Taxi, setTariffTest) {
    float tariff = 0;
    Taxi taxi(1, HONDA, RED, tariff);
    for (int i = 0; i < 10; i++) {
        tariff = (rand() / RAND_MAX) + (rand() % 100);
        taxi.setTariff(tariff);
        ASSERT_EQ(tariff, taxi.getTariff());
    }
}

TEST(Taxi, moveOneStepTest){
    Taxi taxi(1, HONDA, RED, 1);
    Point location = taxi.getLocation();
    Point nextLocation(location.getX(), location.getY() + 1);
    taxi.moveOneStep(nextLocation);
    EXPECT_EQ(taxi.getLocation(), nextLocation);
    //try to move more then 1 cell
    nextLocation= Point(location.getX() + 2, location.getY() + 2);
    EXPECT_THROW(taxi.moveOneStep(nextLocation), exception);
    //tests for out of map next location in driver tests
}

TEST(Taxi, timePassedTest){
    Taxi taxi(1, HONDA, RED, 1);
    taxi.timePassed();

}
