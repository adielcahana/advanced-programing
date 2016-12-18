#include <gtest/gtest.h>
#include <fstream>
#include "../src/Parser.h"

using namespace std;
TEST(ParserTest, readMapTest){
    Parser pars;
    ifstream readMap("../testsFiles/readMap.txt");
    cin.rdbuf(readMap.rdbuf()); //redirect std::cin
    Map* map = NULL;
    EXPECT_NO_THROW(map = pars.readMap());
    delete map;
    EXPECT_THROW(pars.readMap(), exception);
    EXPECT_THROW(pars.readMap(), exception);
    readMap.close();
    cin.clear();
}

TEST(ParserTest, readDriverTest){
    string buffer;
    Parser pars;
    ifstream in("../testsFiles/readDriver.txt");
    cin.rdbuf(in.rdbuf()); //redirect std::cin
    Driver* driver = NULL;
    EXPECT_NO_THROW(driver = pars.readDriver());
    delete driver;
    EXPECT_THROW(pars.readDriver(), exception);
    EXPECT_THROW(pars.readDriver(), exception);
    in.close();
    cin.clear();
}

TEST(ParserTest, readTripTest){
    Parser pars;
    ifstream in("../testsFiles/readTrip.txt");
    cin.rdbuf(in.rdbuf()); //redirect std::cin
    Trip* trip = NULL;
    EXPECT_NO_THROW(trip = pars.readTrip());
    delete trip;
    EXPECT_THROW(pars.readTrip(), exception);
    EXPECT_THROW(pars.readTrip(), exception);
    in.close();
    cin.clear();
}

TEST(ParserTest, readTaxiTest){
    Parser pars;
    ifstream in("../testsFiles/readTaxi.txt");
    cin.rdbuf(in.rdbuf()); //redirect std::cin
    Taxi* taxi = NULL;
    EXPECT_NO_THROW(taxi = pars.readTaxi());
    delete taxi;
    EXPECT_THROW(pars.readTaxi(), exception);
    EXPECT_THROW(pars.readTaxi(), exception);
    in.close();
    cin.clear();
}