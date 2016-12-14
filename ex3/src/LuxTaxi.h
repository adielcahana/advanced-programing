#ifndef ASS2_LUXTAXI_H
#define ASS2_LUXTAXI_H

#include "Driver.h"

class LuxTaxi: public Taxi {
public:
    LuxTaxi(int id, Manufacturer type, Color color):
            Taxi(id,type,color){}

    void moveOneStep(Point* point);
};


#endif //ASS2_LUXTAXI_H
