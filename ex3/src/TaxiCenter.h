#ifndef ASS2_TAXICENTER_H
#define ASS2_TAXICENTER_H

#include "Trip.h"
#include "TripListener.h"

class TaxiCenter{
private:
    vector <Driver*>* drivers;
    vector <Driver*>* avaliableDrivers;
    vector <Taxi*>* avaliableCabs;
    Map* map;
    TripListener* avaliableDriversListener;
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
    Point * getDriverLocation(int id);
    bool shouldStop();
};

#endif //ASS2_TAXICENTER_H
