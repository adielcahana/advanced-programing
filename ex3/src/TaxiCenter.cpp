#include "TaxiCenter.h"

//Driver TaxiCenter::findClosestDriver(Point point){}
TaxiCenter::TaxiCenter(Map* map){
    drivers = new vector <Driver*>;
    avaliableDrivers = new vector <Driver*>();
    avaliableCabs = new vector <Taxi*>();
    avaliableDriverslistener = new NoTripListener(avaliableDrivers);
    this->map = map;
}

TaxiCenter::~TaxiCenter() {
    drivers->clear();
    delete drivers;
    avaliableCabs->clear();
    delete avaliableCabs;
    delete map;
}

void TaxiCenter::addDriver(Driver *driver){
    this->drivers->push_back(driver);
    Taxi* taxi = searchTaxiById(driver->getTaxiId());
    driver->setTaxi(taxi);
    this->avaliableDrivers->push_back(driver);
    driver->addAvaliableListener(this->avaliableDriverslistener);
}

void TaxiCenter::addAvaliableTaxi(Taxi *taxi){
    this->avaliableCabs->push_back(taxi);
}

Taxi* TaxiCenter::searchTaxiById(int id){
    Taxi* temp = NULL;
    for(int i = 0; i < this->avaliableCabs->size(); i++){
        temp = this->avaliableCabs->at(i);
        if(temp->getId() == id){
            temp = new Taxi(*this->avaliableCabs->at(i));
            this->avaliableCabs->erase(this->avaliableCabs->begin() + i);
            return temp;
        }
    }
}

void TaxiCenter::notifyNewTrip(Trip* trip){
    Driver *driver = NULL;
    for(int i = 0; i < this->avaliableDrivers->size(); i++){
        driver = this->avaliableDrivers->at(i);
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