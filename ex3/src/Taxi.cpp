#include "Taxi.h"

Taxi::Taxi(Taxi& other){
    id = other.id;
    totalKm = other.totalKm;
    manufacturer = other.manufacturer;
    color = other.color;
    tariff = other.tariff;
    location = new Point(*other.location);
    velocity = other.velocity;
}

int Taxi::getId(){
    return this->id;
}

void Taxi::addKm(float km){
    this->totalKm += km;
}

void Taxi::setTariff(float tariff){
    this->tariff = tariff;
}

float Taxi::getTariff(){
    return this->tariff;
}
//todo
void Taxi::moveOneStep(Point* point){
    this->updateLocation(point);
    this->addKm(0.001);
}

void Taxi::updateLocation(Point* location){
    delete this->location;
    this->location = location;
}

Point* Taxi::getLocation(){
    return this->location;
}

float Taxi::getKm(){
    return this->totalKm;
}

bool Taxi::operator==(const Taxi &rhs) const {
    return id == rhs.id;
}

bool Taxi::operator!=(const Taxi &rhs) const {
    return !(rhs == *this);
}



