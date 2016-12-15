#ifndef ASS2_TRIP_H
#define ASS2_TRIP_H

#include "Passenger.h"

class Trip {
private:
    friend class TaxiCenter;
    int id;
    int totalMeterPassed;
    Point start;
    Point end;
    int numOfPass;
    vector <Point*>* route;
    double price;
    vector <Passenger*> passengers;
    void addMeter();
public:
    Trip(int id, Point start, Point end, int numOfPass, double price);
    ~Trip();
    Point* getNextPoint();
    double getPrice();
    int getNumPassengers();
    int sumOfSatisfaction();
};

#endif //ASS2_TRIP_H
