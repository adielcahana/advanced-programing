//
// Created by ori on 28/11/16.
//

#ifndef ASS2_DRIVERINFO_H
#define ASS2_DRIVERINFO_H

#include "Driver.h"
#include "Map.h"

class DriverInfo {
private:
    Driver driver;
    Taxi cab;
    Point Location;
    Trip trip;
    void setLocation(Point location);
public:
    DriverInfo(Driver driver, Taxi taxi, Point location, Trip trip)
    Point getLocation();
};


#endif //ASS2_DRIVERINFO_H
