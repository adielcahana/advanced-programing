//
// Created by ori on 28/11/16.
//

#include "Flow.h"
Flow::Flow(){
    Map* map = parser.readMap();
    this->center = new TaxiCenter(map);
}

//todo: seperate initialize and run
void Flow::initilize(){
    int option;
    char dummy;
    bool shouldStop = false;
    int id;
    while(!shouldStop){
        cin >> option;
        cin >> dummy;
        switch(option){
            case 1:
                center->addDriver(parser.readDriver());
                break;
            case 2:
                center->addTrip(parser.readTrip());
                break;
            case 3:
                center->addTaxi(parser.readTaxi());
                break;
            case 4:
                cin >> id;
                Point p = center->getLocation(parser.readTaxi(id));
                cout << p << endl;
                break;
            case 6:
                this->run();
                break;
            case 7:
                delete center;
                shouldStop = true;
                break;
        }
    }
}
void Flow::run(){
    while(!center->shouldStop()){
        center->timePassed();
    }
}
