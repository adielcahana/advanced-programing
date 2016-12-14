#include "Driver.h"

void Driver::calcAvg(){
    int avrage = (avgSatisfaction * passCount) + trip->sumOfSatisfaction();
    addPassCount(trip->getNumPassengers());
    avgSatisfaction = avrage / passCount;
}

void Driver::addPassCount(int passengers){
    passCount += this->trip->getNumPassengers();
}

void Driver::setAge(int age){
    this->age = age;
}

void Driver::setStatus(Status status){
    this->maritalStat = status;
}

Status Driver::getStatus(){
    return maritalStat;
}

void Driver::setExp(int exp){
    this->exp = exp;
}

void Driver::newTrip(Trip* trip){
    this->trip = trip;
}

void Driver::timePassed(){
    if(this->isAvaliable()){
        return;
    }
    moveOneStep();
}

float Driver::getSatisfacation(){
    return this->avgSatisfaction;
}

//todo fix
void Driver::moveOneStep() {
    Point *nextPoint = NULL;
    for (int i = 0; i < this->getTaxi()->getTariff(); i++) {
        nextPoint = this->trip->getNextPoint();
        if (nextPoint == NULL) {
            this->calcAvg();
            delete trip;
            this->trip = NULL;
            delete nextPoint;
            return;
        }
        this->location = nextPoint;
        this->getTaxi()->moveOneStep(nextPoint);
        delete nextPoint;
    }
}

Point* Driver::getLocation(){
    return this->location;
}

float Driver::getPayment(){
    return 0;
}

bool Driver::isAvaliable(){
    return (this->trip == NULL);
}

int Driver::getAge() {
    this->age;
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
