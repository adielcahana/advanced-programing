//
// Created by ori on 28/11/16.
//

#ifndef ASS2_TAXI_H
#define ASS2_TAXI_H

#include "Map.h"
#include "Sprite.h"

enum Type {HONDA, SUBARO, TESLA, FIAT};
enum Color {RED, BLUE, GREEN, PINK, WHITE};

class Taxi : public Sprite{
private:
    int id;
    float totalKm;
    Type manufacturer;
    Color color;
    float tariff;
    Point location;
    int velocity;
    void addKm(float km);
public:
    void setTariff(float tariff);
    float getTariff();
    void moveOneStep(Point);
    void updateLocation();
    Point getLocation();
    void timePassed();
};


#endif //ASS2_TAXI_H
