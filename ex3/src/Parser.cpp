#include "Parser.h"
bool Parser::isValidTripInput(){
    bool readComma = true;
    bool readDot = false;
    int commaCounter = 0;
    for(int i=0; i<buffer.size() && commaCounter <= 6; i++){
        if(readComma){
            if(!isdigit(buffer[i])){
                return false;
            }
            readComma = false;
        } else {
            if(buffer[i] == ',') {
                readComma = true;
                commaCounter++;
                continue;
            }else if(commaCounter == 6 && buffer[i] == '.' && !readDot) {
                readDot = true;
                continue;
            } else if(!isdigit(buffer[i])){
                return false;
            }
        }
    }
    return commaCounter == 6;
}

bool Parser::isValidTaxiInput(){
    int commaCounter = 0;
    for(int i=0; i<buffer.size() && commaCounter <= 3; i++){
        if(commaCounter < 2){
            if(buffer[i] == ','){
                commaCounter++;
                continue;
            } else if(!isdigit(buffer[i])){
                return false;
            }
        } else {
            if(buffer[i] == ','){
                commaCounter++;
                continue;
            } else if(!isalpha(buffer[i])){
                return false;
            }
        }
    }
    return commaCounter == 3;
}

bool Parser::isValidDriverInput() {
    int commaCounter = 0;
    bool readAlpha = false;
    for(int i=0; i<buffer.size() && commaCounter <= 4; i++){
        if(commaCounter == 2 && !readAlpha){
            if(!isalpha(buffer[i])) {
                return false;
            }
            readAlpha = true;
            continue;
        } else {
            if(buffer[i] == ','){
                commaCounter++;
                continue;
            } else if(!isdigit(buffer[i])){
                return false;
            }
        }
    }
    return commaCounter == 4;
}

Map* Parser::readMap() {
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int width, length;
    char *x, *y;
    vector<Point *> *obstacles;
    //verify that x and y are digits
    if ((x = strtok(c, " ")) == NULL) throw runtime_error("bad arguments for map");
    for (int i = 0; x[i] != 0; i++) {
        if (!isdigit(x[i])) throw runtime_error("bad arguments for map");
    }
    if ((y = strtok(NULL, " ")) == NULL) throw runtime_error("bad arguments for map");
    for (int i = 0; y[i] != 0; i++) {
        if (!isdigit(y[i])) throw runtime_error("bad arguments for map");
    }
    width = atoi(x);
    length = atoi(y);
    obstacles = this->readObstacles();
    delete[](c);
    return new Map(width, length, obstacles);
}

Driver* Parser::readDriver(){
    getline(cin, buffer);
    if(!isValidDriverInput()) throw runtime_error("bad argument for new driver");
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int id, age, exp, vehicle_id;
    id = atoi(strtok(c, ","));
    age = atoi(strtok(NULL, ","));
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
            throw runtime_error("bad argument for new driver");
    }
    exp = atoi(strtok(NULL, ","));
    vehicle_id = atoi(strtok(NULL, ","));
    delete[](c);
    return new Driver(id,age,stat,exp,vehicle_id);
}

Trip* Parser::readTrip(){
    getline(cin, buffer);
    if (!isValidTripInput()) throw runtime_error("bad argument for new Trip");
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
    delete[] (c);
    return new Trip(id, start, end, numOfPassengers, taarif);
}

Taxi* Parser::readTaxi(){
    getline(cin, buffer);
    if (!isValidTaxiInput()) throw runtime_error("bad argument for new taxi");
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    int id, taxiType;
    id = atoi(strtok(c, ","));
    taxiType =  atoi(strtok(NULL, ","));
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
            throw runtime_error("bad argument for taxi manufacturer");
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
            throw runtime_error("bad argument for taxi color");
    }
    delete[](c);
    if (taxiType == 1) {
        return new Taxi(id, manufacturer, color);
    } else {
        return new LuxTaxi(id, manufacturer, color);
    }
}

vector<Point*>* Parser::readObstacles(){
    vector<Point*>* obstacles = new vector<Point*>();
    //get number of obstacles
    getline(cin, buffer);
    char *c = new char[buffer.length() + 1];
    strcpy(c, buffer.c_str());
    //verify that c is digits
    for (int i = 0; c[i] != 0; i++) {
        if (!isdigit(c[i])) throw runtime_error("bad arguments for obstacles");
    }
    int numOfObsatcles = atoi(c);;
    delete[](c);
    for(int i = 0; i < numOfObsatcles; i++){
        getline(cin, buffer);
        obstacles->push_back(Point::deserialize(buffer));
    }
    return obstacles;
}