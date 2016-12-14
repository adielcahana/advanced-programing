#ifndef ASS2_TRIP_H
#define ASS2_TRIP_H

#include "Passenger.h"
#include "TaxiCenter.h"

class Trip {
private:
    friend class TaxiCenter;
    int id;
    int totalMeterPassed;
    Point start;
    Point end;
    int numOfPass;
    vector <Point*>* route;
    float price;
    vector <Passenger*>* passengers;
    void addMeter();
public:
    Trip(int id, Point start, Point end, int numOfPass, float price):
        id(id), start(start), end(end), numOfPass(numOfPass), price(price),
        totalMeterPassed(0){};
    Point* getNextPoint();
    void setPrice(float price);
    float getPrice();
    int getNumPassengers();
    int sumOfSatisfaction();
};

#endif //ASS2_TRIP_H
