//
// Created by adi on 04/12/16.
//
#include "BfsTest.h"
void BfsTest::SetUp() {
    int width = 10;
    int length = 10;
    map = new Map(width, length);
    Point* maxPoint = new Point(width,length);
    bfs = Bfs(maxPoint);
    delete maxPoint;
}

void BfsTest::TearDown() {
    delete map;
}

TEST_F(BfsTest, ShortestRouteTest){
    Point* src = new Point(0,0);
    Point* dest = new Point(10,10);
    vector<Node*>* route = bfs.find_shortest_route(map, src, dest, new PointComparator());
    vector<Node*>* shortestRoute = new vector<Node*>();
    for(int i= 0; i < 10; i++){
        shortestRoute->push_back(new Point(0,i));
    }
    for(int i= 0; i < 10; i++){
        shortestRoute->push_back(new Point(i,9));
    }
    while(shortestRoute->size() != 0){
        ASSERT_EQ(shortestRoute->back(), route->back());
        delete shortestRoute->back();
        shortestRoute->pop_back();
        delete route->back();
        route->pop_back();
    }
}



