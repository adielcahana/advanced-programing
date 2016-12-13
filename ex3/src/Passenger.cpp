//
// Created by ori on 28/11/16.
//

#include "Passenger.h"

int Passenger::satisfacation(){
    srand (time(NULL));
    return rand() % 5 + 1;
}