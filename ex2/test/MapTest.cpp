#include <gtest/gtest.h>
#include "../Map.h"

//
// Created by adi on 04/12/16.
//

bool isAdjacent(Point* src, Point* neighbor){
    if (((src->getX() == neighbor->getX() + 1) || (src->getX() == neighbor->getX() - 1)) &&
            (src->getY() == neighbor->getY())){
        return 1;
    } else if (((src->getY() == neighbor->getY() + 1) || (src->getY() == neighbor->getY() - 1)) &&
               (src->getX() == neighbor->getX())){
        return 1;
    }
    return 0;
}

TEST(MapTest, MapBoundryTest){
    Map* map;
    Point* p;
    int x,y;
    int width;
    int length;
    for(int i = 0; i < 10; i++){
        width = rand() % 100;
        length = rand() % 100;
        map = new Map(width,length);
        x = rand() % 150;
        y= rand() % 150;
        p = new Point(x, y);
        if (x < 0 || x >= width || y < 0 || y >= length){
            EXPECT_THROW(map->getAdjacent(p), exception);
        }
        delete p;
        delete map;
    }
}

TEST(MapTest, MapAdjacentTest){
    int width = 10;
    int length = 10;
    Map map(width, length);
    Point* p;
    Point* neighbor;
    int x,y;
    for(int i = 0; i < 10; i++){
        x = rand() % 10;
        y = rand() % 10;
        p = new Point(x, y);
        queue<Node*>* adjacents = map.getAdjacent(p);
        while (!adjacents->empty()){
            neighbor = (Point*) adjacents->front();
            EXPECT_TRUE(isAdjacent(p, neighbor));
            delete neighbor;
            adjacents->pop();
        }
        delete adjacents;
        delete p;
    }
}
//todo: more tests
TEST(MapTest, MapRouteTest){};
TEST(MapTest, MapDeserializationTest){};
