#ifndef ASS2_LUXTAXI_H
#define ASS2_LUXTAXI_H

#include "Driver.h"

class LuxTaxi: public Taxi {
private:
    float tariff;
    int velocity;
public:
    LuxTaxi(int id, Manufacturer type, Color color):
            Taxi(id, type, color), tariff(2), velocity(2){};
};


#endif //ASS2_LUXTAXI_H
