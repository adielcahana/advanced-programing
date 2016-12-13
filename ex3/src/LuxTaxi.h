#ifndef ASS2_LUXTAXI_H
#define ASS2_LUXTAXI_H

#include "Taxi.h"

class LuxTaxi: public Taxi {
public:
    LuxTaxi(int id, Manufacturer type, Color color, float tariff, Point location):
            Taxi(id,type,color,location){}
    void setTariff(float tariff);
    void moveOneStep();
};


#endif //ASS2_LUXTAXI_H
