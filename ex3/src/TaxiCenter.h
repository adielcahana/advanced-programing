#ifndef ASS2_TAXICENTER_H
#define ASS2_TAXICENTER_H

#include "Trip.h"
#include "NoTripListener.h"

class TaxiCenter{
private:
    vector <Driver*>* drivers;
    vector <Driver*>* avaliableDrivers;
    vector <Taxi*>* avaliableCabs;
    NoTripListener* avaliableDriverslistener;
    Map* map;
    //Driver findClosestDriver(Point point);
    void notifyNewTrip(Trip* trip);
public:
    TaxiCenter(Map* map);
    ~TaxiCenter();
    void addDriver(Driver *driver);
    void addAvaliableTaxi(Taxi *taxi);
    Taxi * searchTaxiById(int id);
    void addTrip(Trip* trip);
    void timePassed();
    Point * getLocation(int id);
    bool shouldStop();
};

#endif //ASS2_TAXICENTER_H
