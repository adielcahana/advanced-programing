//
// Created by ori on 28/11/16.
//

#ifndef ASS2_TRIP_H
#define ASS2_TRIP_H

#include "Passenger.h"

class Trip {
private:
    int id;
    int totalMeterPassed;
    Point start;
    Point end;
    int numOfPass;
    vector <Point> route;
    float tariff;
    vector <Passenger> passengers;
    void addMeter();
public:
    Point getNextPoint();
    void setPrice(float price);
};


#endif //ASS2_TRIP_H
