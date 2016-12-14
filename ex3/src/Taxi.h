#ifndef ASS2_TAXI_H
#define ASS2_TAXI_H

#include "Map.h"
#include "Trip.h"

enum Manufacturer {HONDA, SUBARO, TESLA, FIAT};
enum Color {RED, BLUE, GREEN, PINK, WHITE};

class Taxi{
protected:
    int id;
    float totalKm;
    Manufacturer manufacturer;
    Color color;
    float tariff;
    Point* location;
    int velocity;
    void addKm(float km);
public:
    Taxi(int id, Manufacturer type, Color color):
            id(id), manufacturer(type), color(color), tariff(1), velocity(1){};
    Taxi(Taxi &other);
    int getId();
    virtual void setTariff(float tariff);
    float getKm();
    float getTariff();
    virtual void moveOneStep(Point* point);
    void updateLocation(Point* location);
    Point* getLocation();
    bool operator==(const Taxi &rhs) const;
    bool operator!=(const Taxi &rhs) const;
};


#endif //ASS2_TAXI_H
