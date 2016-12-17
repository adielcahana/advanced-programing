//
// Created by ori on 28/11/16.
//

#include "Flow.h"
Flow::Flow(){
    Map* map = parser.readMap();
    this->center = new TaxiCenter(map);
}

Flow::~Flow(){
    delete center;
}

void Flow::initialize(){
    int option;
    char dummy;
    Point* p = NULL;
    bool shouldStop = false;
    int id;
    while(!shouldStop){
        cin >> option;
        cin >> noskipws >> dummy;
        switch(option){
            case 1:
                center->addDriver(parser.readDriver());
                break;
            case 2:
                center->addTrip(parser.readTrip());
                break;
            case 3:
                center->addAvaliableTaxi(parser.readTaxi());
                break;
            case 4:
                cin >> id;
                cin >> noskipws >> dummy;
                p = center->getDriverLocation(id);
                if(p != NULL){
                    cout<< *p << endl;
                    delete p;
                }
                else {
                    cout << "driver id doesn't exist" << endl;
                }
                break;
            case 6:
                this->run();
                break;
            case 7:
                shouldStop = true;
                break;
            default:
                break;
        }
    }
}

void Flow::run(){
    while(!center->shouldStop()){
        center->timePassed();
    }
}
