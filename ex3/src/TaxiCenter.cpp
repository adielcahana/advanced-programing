#include "TaxiCenter.h"

//Driver TaxiCenter::findClosestDriver(Point point){}
TaxiCenter::TaxiCenter(Map* map){
    drivers = new vector <Driver*>;
    avaliableDrivers = new vector <Driver*>;
    avaliableCabs = new vector <Taxi*>();
    avaliableDriversListener = new NoTripListener(avaliableDrivers);
    this->map = map;
}

TaxiCenter::~TaxiCenter() {
    for(int i = 0; i < drivers->size(); i++){
        delete drivers->at(i)->getTaxi();
        delete drivers->at(i);
    }
    for(int i = 0; i < avaliableCabs->size(); i++){
        delete avaliableCabs->at(i);
    }
    delete drivers;
    delete avaliableDrivers;
    avaliableCabs->clear();
    delete avaliableCabs;
    delete avaliableDriversListener;
    delete map;
}

void TaxiCenter::addDriver(Driver *driver){
    this->drivers->push_back(driver);
    Taxi* taxi = searchTaxiById(driver->getTaxiId());
    driver->setTaxi(taxi);
    driver->addAvaliableListener(avaliableDriversListener);
    avaliableDrivers->push_back(driver);
}

void TaxiCenter::addAvaliableTaxi(Taxi *taxi){
    this->avaliableCabs->push_back(taxi);
}

Taxi* TaxiCenter::searchTaxiById(int id){
    Taxi* taxi = NULL;
    for(int i = 0; i < this->avaliableCabs->size(); i++){
        taxi = this->avaliableCabs->at(i);
        if(taxi->getId() == id){
            taxi = this->avaliableCabs->at(i);
            this->avaliableCabs->erase(this->avaliableCabs->begin() + i);
            return taxi;
        }
    }
    return NULL;
}

void TaxiCenter::notifyNewTrip(Trip* trip){
    Driver *driver = NULL;
    Point* location = NULL;
    for(int i = 0; i < this->avaliableDrivers->size(); i++){
        driver = this->avaliableDrivers->at(i);
        location = driver->getLocation();
        if(trip->start == *location){
            driver->newTrip(trip);
            delete location;
            return;
        }
        delete location;
    }
}

void TaxiCenter::addTrip(Trip* trip){
    Point* start = new Point(trip->start);
    Point* end = new Point(trip->end);
    trip->route = map->getRoute(start, end);
    notifyNewTrip(trip);
    delete end;
}

void TaxiCenter::timePassed(){
    for(int i = 0; i < drivers->size(); i++){
        drivers->at(i)->timePassed();
    }
}

bool TaxiCenter::shouldStop(){
    return (avaliableDrivers->size() == drivers->size());
}

Point * TaxiCenter::getLocation(int id){
    Point* point = NULL;
    Driver *driver = NULL;
    for(int i = 0; i < this->drivers->size(); i++){
        driver = this->drivers->at(i);
        if(driver->getId() == id){
            point = driver->getLocation();
            return point;
        }
    }
    return NULL;
}