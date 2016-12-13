#include "Trip.h"

Trip::Trip(int id, Point start, Point end, int numOfPass, float price):
        id(id), start(start), end(end), numOfPass(numOfPass), price(price) {
    for (int i = 0; i < this->numOfPass; i++) {
        passengers->push_back(new Passenger());
    }
}

void Trip::addMeter(){
    this->totalMeterPassed += 1;
}

Point* Trip::getNextPoint(){
    Point* nextPoint = new Point(*this->route->front());
    delete this->route->front();
    this->route->erase(route->begin());
    this->addMeter();
    return nextPoint;
}

void Trip::setPrice(float price){
    this->price = price;
}

float Trip::getPrice() {
    return this->price;
}

int Trip::getNumPassengers(){
    return numOfPass;
}

int Trip::sumOfSatisfaction() {
    int sum = 0;
    for (int i = 0; i < this->passengers->size(); i++){
        sum += this->passengers->at(i)->satisfacation();
    }
    return sum;
}
