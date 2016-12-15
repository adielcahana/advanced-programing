#include "Parser.h"

Map* Parser::readMap(){
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int width = atoi(strtok(c, " "));
    int length = atoi(strtok(NULL, " "));
    vector<Point*>* obstacles = this->readObstacles();
    delete c;
    return new Map(width, length, obstacles);
}

Driver* Parser::readDriver(){
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int id = atoi(strtok(c, ","));
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
    delete c;
    return new Driver(id,age,stat,exp,vehicle_id);
}

Trip* Parser::readTrip(){
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int id = atoi(strtok(c, ","));
    char *x = strtok(NULL, ",");
    char *y = strtok(NULL, ",");
    Point start(atoi(x),atoi(y));
    x = strtok(NULL, ",");
    y = strtok(NULL, ",");
    Point end(atoi(x),atoi(y));
    int numOfPassengers = atoi(strtok(NULL, ","));
    double taarif = strtod(strtok(NULL, ","), NULL);
    delete c;
    return new Trip(id, start, end, numOfPassengers, taarif);
}

Taxi* Parser::readTaxi(){
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int id = atoi(strtok(c, ","));
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
    delete c;
    if (taxiType == 1) {
        return new Taxi(id, manufacturer, color);
    } else {
        return new LuxTaxi(id, manufacturer, color);
    }
}

vector<Point*>* Parser::readObstacles(){
    vector<Point*>* obstacles = new vector<Point*>();
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int numOfObsatcles = atoi(c);
    delete c;
    for(int i = 0; i < numOfObsatcles; i++){
        getline(cin, buffer);
        obstacles->push_back(Point::deserialize(buffer));
    }
    return obstacles;
}