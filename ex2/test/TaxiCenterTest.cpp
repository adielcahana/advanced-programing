
#include "gtest/gtest.h"
#include "../TaxiCenter.h"

TEST(TaxiCenter, startTest){
    vector <DriverInfo> employees;
    Map* map = new Map(10,10);
    TaxiCenter taxiCenter = TaxiCenter(map, employees);
    taxiCenter.start();
    EXPECT_NO_THROW("Somthing wrong");
    delete map;
}

TEST(TaxiCenter, timePassedTest){

}