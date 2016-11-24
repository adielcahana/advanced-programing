#include <iostream>
#include "Map.h"

#define INPUT_SIZE 20

using namespace std;


int main(){
    //get the input and parse it
    char input[INPUT_SIZE];
    cin >> input;
    char* gridSize = strtok(input,",");
    char* point1 = strtok(NULL, ",");
    char* point2 = strtok(NULL, ",");
    Map* g = Map::deserialize(gridSize);
    Point* p1 = Point::deserialize(point1);
    Point* p2 = Point::deserialize(point2);
    try {
        //might return an "out of bounds" exception
        vector<Point *> *route = g->getRoute(p1, p2);
        for( int i = 0; i < route->size(); i++){
            p1 = route->at(i);
            cout << *p1 << endl;
            delete p1;
        }
        route->clear();
        delete route;
     } catch (const char* msg){
        cout << msg << endl;
        delete p1;
    }
    delete g;
    delete p2;
    return 0;
}