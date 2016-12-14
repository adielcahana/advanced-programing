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
public:
    TaxiCenter(Map* map): drivers(NULL), avaliableCabs(NULL), map(map){};
    Driver* addDriver(Driver* driver);
    Taxi* addAvaliableTaxi(Taxi *taxi);
    void searchTaxiById(Driver* driver);
    void addTrip(Trip* trip);
    void timePassed();
    Point getLocation(int id);
    bool shouldStop();
};


#endif //ASS2_TAXICENTER_H
