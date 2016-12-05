
#include "Driver.h"

void Driver::calcAvg(int average){}

void Driver::addPassCount(int passengers){}

void Driver::setTaxi(Taxi taxi){}

void Driver::setAge(int age){}

void Driver::setStatus(Status status){}

Status Driver::getStatus(){
    return SINGLE;
}

void Driver::setExp(int exp){}

void Driver::newTrip(Trip trip){}

void Driver::timePassed(){}

void Driver::moveOneStep(){}

float Driver::getPayment(){
    return 0;
}

bool Driver::isAvaliable(){
    return true;
}

int Driver::getAge() {
    return 0;
}

Taxi Driver::getTaxi() {
    return this->taxi;
}
