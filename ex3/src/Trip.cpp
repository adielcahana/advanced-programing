#include "Trip.h"

Trip::Trip(int id, Point start, Point end, int numOfPass, double price):
        id(id), start(start), end(end), numOfPass(numOfPass), price(price) {
    for (int i = 0; i < this->numOfPass; i++) {
        passengers.push_back(new Passenger());
    }
}

Trip::~Trip() {
    if(this->route != NULL){
        for (int i = 0; i < route->size(); i++){
            delete route->at(i);
        }
        route->clear();
    }
    for(int j = 0; j < passengers.size(); j++){
        delete passengers.at(j);
    }
    passengers.clear();
}

void Trip::addMeter(){
    this->totalMeterPassed += 1;
}

Point* Trip::getNextPoint(){
    Point* nextPoint = this->route->front();
    if (nextPoint != NULL){
        //safe copy
        nextPoint = new Point(*nextPoint);
        this->addMeter();
        if (route->size() != 0) {
            this->route->erase(route->begin());
            return nextPoint;
        }
        if (route->size() == 0) {
            this->route->clear();
            nextPoint = NULL;
        }
    }
    return nextPoint;
}

double Trip::getPrice() {
    return this->price;
}

int Trip::getNumPassengers(){
    return numOfPass;
}

int Trip::sumOfSatisfaction() {
    int sum = 0;
    for (int i = 0; i < this->passengers.size(); i++){
        sum += this->passengers.at(i)->satisfacation();
    }
    return sum;
}
