//
// Created by adi on 06/12/16.
//

#ifndef EX2_POINTTEST_H
#define EX2_POINTTEST_H

#include <gtest/gtest.h>
#include "Map.h"

TEST(PointTest, getterTest){
    Point p(0,0);
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 100;
        y = rand() % 100;
        p = Point(x,y);
        EXPECT_EQ(p.getX(), x);
        EXPECT_EQ(p.getY(), y);
    }
}

TEST(PointTest, hashTest){
    Point arr[10];
    arr[0] = Point(83,86);
    arr[1] = Point(77,15);
    arr[2] = Point(93,35);
    arr[3] = Point(86,92);
    arr[4] = Point(49,21);
    arr[5] = Point(62,27);
    arr[6] = Point(90,59);
    arr[7] = Point(63,26);
    arr[8] = Point(40,26);
    arr[9] = Point(72,36);
    EXPECT_EQ(arr[0].hash(), 14448);
    EXPECT_EQ(arr[1].hash(), 4355);
    EXPECT_EQ(arr[2].hash(), 8349);
    EXPECT_EQ(arr[3].hash(), 16017);
    EXPECT_EQ(arr[4].hash(), 2534);
    EXPECT_EQ(arr[5].hash(), 4067);
    EXPECT_EQ(arr[6].hash(), 11265);
    EXPECT_EQ(arr[7].hash(), 4068);
    EXPECT_EQ(arr[8].hash(), 2251);
    EXPECT_EQ(arr[9].hash(), 5958);
}

TEST(PointTest, equalityOperatorsTest) {
    Point point(0,0);
    Point other(0,0);
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 100;
        y = rand() % 100;
        point = Point(x,y);
        //y+1 in case random gives the same number
        other = Point(y + 1,x);
        EXPECT_EQ(point, point);
        EXPECT_NE(point, other);
        EXPECT_EQ(other, other);
    }
}

TEST(PointTest, PointDeserializationTest){
    Point *p = NULL;
    int x,y;
    for(int i = 0; i < 10; i++){
        char str[] = "00_00";
        x = rand() % 100;
        y = rand() % 100;
        str[0] =  48 +  x / 10;
        str[1] =  48 +  x % 10;
        str[3] = 48 + y / 10 ;
        str[4] =  48 + y % 10 ;
        p = Point::deserialize(str);
        EXPECT_EQ(*p, Point(x,y));
    }
}




#endif //EX2_POINTTEST_H
