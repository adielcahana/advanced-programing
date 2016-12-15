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
    void addKm(float km);
public:
    Taxi(int id, Manufacturer type, Color color, float tariff = 1):
            id(id), manufacturer(type), color(color),totalKm(0), tariff(1) {location = new Point(0,0);};
    Taxi(int id, Manufacturer type, Color color, Point* location):
            id(id), manufacturer(type), color(color),totalKm(0), tariff(1),
            location(location){};
    Taxi(Taxi &other);
    ~Taxi();
    int getId();
    float getKm();
    float getTariff();
    //todo change in driver
    virtual int getVelocity();
    virtual void moveOneStep(Point* point);
    void updateLocation(Point* location);
    Point* getLocation();
    bool operator==(const Taxi &rhs) const;
    bool operator!=(const Taxi &rhs) const;
};

#endif //ASS2_TAXI_H
