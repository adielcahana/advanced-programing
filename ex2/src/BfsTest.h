//
// Created by adi on 04/12/16.
//

#ifndef EX2_BFSTEST_H
#define EX2_BFSTEST_H

#include <gtest/gtest.h>
#include "Bfs.h"
#include "Map.h"

class BfsTest : public ::testing::Test{
protected:
    Bfs* bfs;
    Map* map;
    virtual void SetUp();
    virtual void TearDown();
public:
    BfsTest();
};
#endif //EX2_BFSTEST_H
