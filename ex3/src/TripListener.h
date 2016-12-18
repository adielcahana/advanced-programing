//
// Created by adi on 15/12/16.
//

#ifndef EX2_NOTRIP_H
#define EX2_NOTRIP_H


#include "AvaliableListener.h"
#include "Driver.h"

class TripListener : public AvaliableListener {
    vector <Driver*>* avaliableDrivers;
public:
    TripListener(vector <Driver*>* avaliabledrivers): avaliableDrivers(avaliabledrivers){};
    void avaliableEvent(AvaliableNotifier *avaliable);
    void unavaliableEvent(AvaliableNotifier *unavaliable);
};


#endif //EX2_NOTRIP_H