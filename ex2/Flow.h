//
// Created by ori on 28/11/16.
//

#ifndef ASS2_FLOW_H
#define ASS2_FLOW_H

#include "SpriteCollection.h"

class Flow {
private:
    vector <Sprite> spriteCollection;
public:
    void initilize();
    void run();
    void notifyTimePassed();
};


#endif //ASS2_FLOW_H
