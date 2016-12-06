#include <gtest/gtest.h>
#include "../Map.h"
using namespace std;
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
            EXPECT_THROW(map->getAdjacent(p), out_of_range);
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
            delete p;
        }
        delete adjacents;
    }
}

//todo: more tests
TEST(MapTest, MapRouteTest){
    PointComparator cmp;
    int x,y;
    int width;
    int length;
    vector<Point*>* route = NULL;
    Point *src, *dest, *temp, *outOfBound;
    Map* map = NULL;
    for(int i = 0; i < 10; i++){
        width = rand() % 100;
        length = rand() % 100;
        map = new Map(width,length);
        x = rand() % 100;
        y = rand() % 100;
        src = new Point(x, y);
        x = rand() % 100;
        y= rand() % 100;
        dest = new Point(x, y);
        route = map->getRoute(src,dest);
        outOfBound = new Point(width + 1, length + 1);
        EXPECT_THROW(map->getRoute(outOfBound,outOfBound), out_of_range);
        delete outOfBound;
        temp = route->at(0);
        EXPECT_TRUE(cmp.equals((Node*) src, (Node*) temp));
        delete src;
        for(int i = 1; i < route->size(); i++){
            temp = route->at(i);
            EXPECT_TRUE(isAdjacent(src,temp));
            src = temp;
        }
        EXPECT_TRUE(cmp.equals((Node*) src, (Node*) dest));
        delete dest;
        /*for(int i = 1; i < route->size(); i++){
            delete route->at(i);
        }*/
        route->clear();
        delete route;
        delete map;
    }
};

TEST(MapTest, MapDeserializationTest){
    int width;
    int length;
    Point* p;
    Map* map = NULL;
    char str[] = "00_00";
    for(int i =0 ; i<10; i++) {
        width = rand() % 100;
        length = rand() % 100;
        p = new Point(width + 1, length + 1);
        str[0] =  (char) width / 10;
        str[1] = (char) width % 10;
        str[3] = (char) length / 10 ;
        str[4] = (char) length % 10 ;
        map = Map::deserialize(str);
        EXPECT_THROW(map->getRoute(p,p), out_of_range);
        delete p;
    }
};
