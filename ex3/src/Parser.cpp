//
// Created by adi on 12/12/16.
//

#include "Parser.h"
#include "LuxTaxi.h"

Map* Parser::readMap(){
    getline(cin, buffer);
    int width = atoi(strtok(buffer, " "));
    int length = atoi(strtok(NULL, " "));
    vector<Point*>* obstacles = this->readObstacles();
    return new Map(width, length, obstacles);
}

Driver* Parser::readDriver(){
    getline(cin, buffer);
    int id = atoi(strtok(buffer, ","));
    int age = atoi(strtok(NULL, ","));
    Status stat;
    switch(strtok(NULL, ",")[0]){
        case 'S':
            stat = SINGLE;
            break;
        case 'M':
            stat = MARRIED;
            break;
        case 'D':
            stat = DIVORCED;
            break;
        case 'W':
            stat = WIDOWED;
            break;
        default:
            throw "bad argument for new driver";
    }
    int exp = atoi(strtok(NULL, ","));
    int vehicle_id = atoi(strtok(NULL, ","));
    return new Driver(id,age,stat,exp,vehicle_id);
}

Trip* Parser::readTrip(){
    getline(cin, buffer);
    int id = atoi(strtok(buffer, ","));
    Point start(atoi(strtok(NULL, ",")),atoi(strtok(NULL, ",")));
    Point end(atoi(strtok(NULL, ",")),atoi(strtok(NULL, ",")));
    int numOfPassengers = atoi(strtok(NULL, ","));
    double taarif = strtod(strtok(NULL, ","), NULL);
    return new Trip(id, start, end, numOfPassengers, taarif);
}

Taxi* Parser::readTaxi(){
    getline(cin, buffer);
    int id = atoi(strtok(buffer, ","));
    int taxiType =  atoi(strtok(NULL, ","));
    Manufacturer manufacturer;
    switch(strtok(NULL, ",")[0]) {
        case 'H':
            manufacturer = HONDA;
            break;
        case 'S':
            manufacturer = SUBARO;
            break;
        case 'T':
            manufacturer = TESLA;
            break;
        case 'F':
            manufacturer = FIAT;
            break;
        default:
            throw "bad argument for taxi manufacturer";
    }
    Color color;
    switch(strtok(NULL, ",")[0]) {
        case 'R':
            color = RED;
            break;
        case 'B':
            color = BLUE;
            break;
        case 'G':
            color = GREEN;
            break;
        case 'P':
            color = PINK;
            break;
        case 'W':
            color = WHITE;
            break;
        default:
            throw "bad argument for taxi color";
    }
    if (taxiType == 1) {
        return new Taxi(id, manufacturer, color);
    } else {
        return new LuxTaxi(id, manufacturer, color);
    }
}

vector<Point*>* Parser::readObstacles(){
    vector<Point*>* obstacles = new vector<Point*>();
    getline(cin, buffer);
    int numOfObsatcles = atoi(buffer);
    for(int i = 0; i < numOfObsatcles; i++){
        getline(cin, buffer);
        obstacles->push_back(Point::deserialize(buffer));
    }
}