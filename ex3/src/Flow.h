//
// Created by ori on 28/11/16.
//

#ifndef ASS2_FLOW_H
#define ASS2_FLOW_H

#include "Driver.h"
#include "TaxiCenter.h"
#include "Parser.h"

class Flow {
private:
    Parser parser;
    TaxiCenter* center;
public:
    Flow();
    void initilize();
    void run();
};

#endif //ASS2_FLOW_H
