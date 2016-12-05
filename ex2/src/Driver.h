//
// Created by ori on 28/11/16.
//

#ifndef ASS2_DRIVER_H
#define ASS2_DRIVER_H

#include "Sprite.h"
#include "Taxi.h"
#include "Trip.h"

enum Status {SINGLE, MARRIED, DIVORCED, WIDOWED};

class Driver: public Sprite {
private:
    int id;
    int age;
    Status maritalStat;
    int exp;
    float avgSatisfaction;
    int passCount;
    Taxi taxi;
    Map map;
    Trip* trip;
    void calcAvg(int average);
    void addPassCount(int passengers);
    void setTaxi(Taxi taxi);
public:
    Driver(int id, int age, Status status, int exp, Taxi taxi, Map map):
            id(id), age(age),maritalStat(status), exp(exp), taxi(taxi), map(map), trip(NULL){};
    void setAge(int age);
    int getAge();
    Taxi getTaxi();
    void setStatus(Status status);
    Status getStatus();
    void setExp(int exp);
    void newTrip(Trip trip);
    void timePassed();
    void moveOneStep();
    float getPayment();
    bool isAvaliable();
};

#endif //ASS2_DRIVER_H
