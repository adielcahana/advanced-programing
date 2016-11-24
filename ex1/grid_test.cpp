#include <iostream>
#include "grid.h"

#define INPUT_SIZE 20

using namespace std;


int main(){
    char input[INPUT_SIZE];
    cin >> input;
    char* gridSize = strtok(input,",");
    char* point1 = strtok(NULL, ",");
    char* point2 = strtok(NULL, ",");
    Grid* g = Grid::deserialize(gridSize);
    Point* p1 = Point::deserialize(point1);
    Point* p2 = Point::deserialize(point2);
    try {
        vector<Point *> *route = g->get_route(p1, p2);
        int i = route->size() - 1;
        while (i >= 0) {
            p1 = route->at(i);
            cout << *p1 << endl;
            delete p1;
            i--;
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