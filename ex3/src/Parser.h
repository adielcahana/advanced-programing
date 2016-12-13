//
// Created by adi on 12/12/16.
//

#ifndef EX2_PARSE_H
#define EX2_PARSE_H


#include "Driver.h"
#include "LuxTaxi.h"

class Parser {
    string buffer;
public:
    Map* readMap();
    Driver* readDriver();
    Trip* readTrip();
    Taxi* readTaxi();
private:
    vector<Point*>* readObstacles();
};


#endif //EX2_PARSE_H
