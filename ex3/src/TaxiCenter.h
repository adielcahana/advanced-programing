#ifndef ASS2_TAXICENTER_H
#define ASS2_TAXICENTER_H

#include "Driver.h"
#include "Trip.h"

class TaxiCenter{
private:
    vector <Driver*>* drivers;
    vector <Taxi*>* avaliableCabs;
    Map* map;
    //Driver findClosestDriver(Point point);
    void notifyNewTrip(Trip* trip);
    void addTrip(Trip* trip);
public:
    TaxiCenter(Map* map);
    Driver* addDriver(Driver* driver);
    Taxi* addAvaliableTaxi(Taxi *taxi);
    void searchTaxiById(Driver* driver);
    void timePassed();
    Point getLocation(int id);
    bool shouldStop();
};


#endif //ASS2_TAXICENTER_H
