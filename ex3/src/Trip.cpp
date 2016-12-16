#include "Trip.h"

Trip::Trip(int id, Point start, Point end, int numOfPass, double price):
        id(id), start(start), end(end), numOfPass(numOfPass), price(price), route(NULL) {
    for (int i = 0; i < this->numOfPass; i++) {
        passengers.push_back(new Passenger());
    }
}


Trip::~Trip() {
    if(this->route != NULL){
        cout<<route->size()<<endl;
        for (int i = 0; i < route->size(); i++){
            delete route->at(i);
        }
        route->clear();
        delete route;
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
    if (route->size() != 0) {
        Point* nextPoint = this->route->front();
        //safe copy
        nextPoint = new Point(*nextPoint);
        this->addMeter();
        delete route->front();
        this->route->erase(route->begin());
        return nextPoint;
    }
    return NULL;
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
