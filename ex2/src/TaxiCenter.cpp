//
// Created by ori on 28/11/16.
//

#include "TaxiCenter.h"


DriverInfo TaxiCenter::findClosestDriver(){
    vector <Point*> route;
    Trip trip = Trip(5, Point(0,0), Point(1,1), 3, route);
    Taxi taxi = Taxi(1, HONDA, RED, 1, Point(0,0));
    Driver driver = Driver(5, 20, SINGLE, 5, taxi, Map(10,10));
    DriverInfo driverInfo = DriverInfo(driver, taxi, Point(0,0), trip);
    return driverInfo;
}

void TaxiCenter::answerCalls(){}

void TaxiCenter::notifyNewTrip(Trip trip){}

Trip TaxiCenter::createNewTrip(){
    vector <Point*> route;
    Trip trip = Trip(5, Point(0,0), Point(1,1), 3, route);
    return trip;

}

void TaxiCenter::start(){}

void TaxiCenter::timePassed(){}

TaxiCenter::TaxiCenter(Map* map, vector<DriverInfo> employees) {
    this->map = map;
    this->employees = employees;
}
