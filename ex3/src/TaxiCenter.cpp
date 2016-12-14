#include "TaxiCenter.h"

TaxiCenter::TaxiCenter(Map* map) {
    this->map = map;
}

//Driver TaxiCenter::findClosestDriver(Point point){}

Driver* TaxiCenter::addDriver(Driver* driver){
    this->drivers->push_back(driver);
}

Taxi* TaxiCenter::addAvaliableTaxi(Taxi *taxi){
    this->avaliableCabs->push_back(taxi);
}

void TaxiCenter::searchTaxiById(Driver* driver){
    for(int i = 0; i < this->avaliableCabs->size(); i++){
        if(this->avaliableCabs->at(i)->getId() == driver->getTaxiId()){
            Taxi* taxi = new Taxi(*this->avaliableCabs->at(i));
            delete this->avaliableCabs->at(i);
            this->avaliableCabs->erase(this->avaliableCabs->begin() + 1);
            driver->setTaxi(this->avaliableCabs->at(i));
            return;
        }
    }
}

void TaxiCenter::notifyNewTrip(Trip* trip){
    Driver *driver = NULL;
    for(int i = 0; i < this->drivers->size(); i++){
        driver = this->drivers->at(i);
        if(trip->start == *driver->getLocation()){
            driver->newTrip(trip);
            return;
        }
    }
}

void TaxiCenter::addTrip(Trip* trip){
    trip->route = map->getRoute(new Point(trip->start), new Point(trip->end));
    notifyNewTrip(trip);
}

void TaxiCenter::timePassed(){
    for(int i = 0; i < drivers->size(); i++){
        drivers->at(i)->timePassed();
    }
}

bool TaxiCenter::shouldStop(){
    Driver *driver = NULL;
    for(int i = 0; i < this->drivers->size(); i++){
        driver = this->drivers->at(i);
        if(!driver->isAvaliable()) {
            return false;
        }
    }
    return true;
}

Point TaxiCenter::getLocation(int id){
    Point point = Point(0,0);
    Driver *driver = NULL;
    for(int i = 0; i < this->drivers->size(); i++){
        driver = this->drivers->at(i);
        if(driver->getTaxiId() == id){
            point = *driver->getLocation();
            return point;
        }
    }
    return point;
}