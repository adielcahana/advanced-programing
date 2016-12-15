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
    TaxiCenter(Map* map);
    ~TaxiCenter();
    void addDriver(Driver *driver);
    void addAvaliableTaxi(Taxi *taxi);
    Taxi* searchTaxiById(int id);
    void addTrip(Trip* trip);
    void timePassed();
    Point * getLocation(int id);
    bool shouldStop();
};

#endif //ASS2_TAXICENTER_H
