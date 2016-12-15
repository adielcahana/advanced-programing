#ifndef ASS2_DRIVER_H
#define ASS2_DRIVER_H

#include "Taxi.h"
#include "Trip.h"

enum Status {SINGLE, MARRIED, DIVORCED, WIDOWED};

class Driver{
private:
    int id;
    int age;
    Status maritalStat;
    int exp;
    Taxi* taxi;
    int taxiId;
    Trip* trip;
    float avgSatisfaction;
    int passCount;
    Point* location;

    void calcAvg();
    void addPassCount(int passengers);
public:
    Driver(int id, int age, Status status, int exp, int taxiId):
            id(id), age(age),maritalStat(status), exp(exp), taxiId(taxiId),
            trip(NULL), location(new Point(0,0)){};
    void setAge(int age);
    int getId();
    Point * getLocation();
    float getSatisfacation();
    int getAge();
    void setTaxi(Taxi* taxi);
    int getTaxiId();
    Taxi* getTaxi();
    void setStatus(Status status);
    Status getStatus();
    void setExp(int exp);
    void newTrip(Trip* trip);
    void timePassed();
    void moveOneStep();
    float getPayment();
    bool isAvaliable();
};

#endif //ASS2_DRIVER_H
