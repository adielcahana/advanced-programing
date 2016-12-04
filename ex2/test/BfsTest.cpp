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
    PointComparator* cmp = new PointComparator()
    vector<Node*>* route = bfs.find_shortest_route(map, src, dest, cmp);
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
    delete dest;
    delete route;

    src = new Point(9,9);
    dest = new Point(0,0);
    route = bfs.find_shortest_route(map, src, dest, cmp);
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(9,i));
    }
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(i,0));
    }
    while(shortestRoute->size() != 0){
        ASSERT_EQ(shortestRoute->back(), route->back());
        delete shortestRoute->back();
        shortestRoute->pop_back();
        delete route->back();
        route->pop_back();
    }
    delete dest;
    delete route;

    src = new Point(0,9);
    dest = new Point(9,0);
    route = bfs.find_shortest_route(map, src, dest, cmp);
    for(int i= 0; i < 10; i++){
        shortestRoute->push_back(new Point(i,9));
    }
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(9,i));
    }
    while(shortestRoute->size() != 0){
        ASSERT_EQ(shortestRoute->back(), route->back());
        delete shortestRoute->back();
        shortestRoute->pop_back();
        delete route->back();
        route->pop_back();
    }
    delete dest;
    delete route;

    src = new Point(9,0);
    dest = new Point(0,9);
    route = bfs.find_shortest_route(map, src, dest, cmp);
    for(int i= 9; i >= 0; i--){
        shortestRoute->push_back(new Point(i,0));
    }
    for(int i= 0; i < 10; i++){
        shortestRoute->push_back(new Point(0,i));
    }
    while(shortestRoute->size() != 0){
        ASSERT_EQ(shortestRoute->back(), route->back());
        delete shortestRoute->back();
        shortestRoute->pop_back();
        delete route->back();
        route->pop_back();
    }
    delete dest;
    delete route;
    delete cmp;
    delete shortestRoute;
}