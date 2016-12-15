//
// Created by adi on 15/12/16.
//

#ifndef EX2_AVALIABLENOTIFIER_H
#define EX2_AVALIABLENOTIFIER_H

#include "AvaliableListener.h"

class AvaliableNotifier{
public:
    vector <AvaliableListener*> avaliableListeners;
    virtual void addAvaliableListener(AvaliableListener* al) = 0;
    virtual void removeAvaliableListener(AvaliableListener* al) = 0;
};

#endif //EX2_AVALIABLENOTIFIER_H
