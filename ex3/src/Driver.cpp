#include "Driver.h"

void Driver::calcAvg(){
    float avrage = (avgSatisfaction * passCount) + trip->sumOfSatisfaction();
    addPassCount(trip->getNumPassengers());
    avgSatisfaction = avrage / passCount;
}

Driver::~Driver(){
    if (trip != NULL) {
        delete trip;
    }
    if (location != NULL) {
        delete location;
    }
}

void Driver::addPassCount(int passengers){
    passCount += this->trip->getNumPassengers();
}

void Driver::newTrip(Trip* trip){
    notifyUnavaliable();
    this->trip = trip;
}

void Driver::timePassed(){
    if(trip == NULL){
        return;
    }
    moveOneStep();
}

void Driver::moveOneStep() {
    Point *nextPoint = NULL;
    for (int i = 0; i < this->getTaxi()->getVelocity(); i++) {
        nextPoint = this->trip->getNextPoint();
        if (nextPoint == NULL) {
            this->calcAvg();
            delete trip;
            this->trip = NULL;
            notifyAvaliable();
            delete nextPoint;
            return;
        }
        delete this->location;
        this->location = nextPoint;
        this->getTaxi()->moveOneStep(nextPoint);
    }
}

Point * Driver::getLocation(){
    return new Point(*this->location);
}

int Driver::getTaxiId(){
    return this->taxiId;
}

Taxi* Driver::getTaxi() {
    return this->taxi;
}

void Driver::setTaxi(Taxi* taxi){
    this->taxi = taxi;
}

int Driver::getId() {
    return this->id;
}

void Driver::addAvaliableListener(AvaliableListener* al){
    this->avaliableListeners.push_back(al);
}

void Driver::removeAvaliableListener(AvaliableListener* al){
    for(int i = 0; i< avaliableListeners.size(); i++){
        if(avaliableListeners.at(i) == al){
            avaliableListeners[i] = NULL;
            avaliableListeners.erase(avaliableListeners.begin() + i);
        }
    }
}

void Driver::notifyAvaliable(){
    for(int i = 0; i< avaliableListeners.size(); i++){
        avaliableListeners[i]->avaliableEvent(this);
    }
}

void Driver::notifyUnavaliable(){
    for(int i = 0; i< avaliableListeners.size(); i++){
        avaliableListeners[i]->unavaliableEvent(this);
    }
}