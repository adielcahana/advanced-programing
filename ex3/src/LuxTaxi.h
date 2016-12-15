#ifndef ASS2_LUXTAXI_H
#define ASS2_LUXTAXI_H

#include "Driver.h"

class LuxTaxi: public Taxi {
private:
public:
    LuxTaxi(int id, Manufacturer type, Color color):
            Taxi(id, type, color, 2){};
    int getVelocity();
};

#endif //ASS2_LUXTAXI_H
