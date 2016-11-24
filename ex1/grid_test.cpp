#include <iostream>
#include <string>
#include "grid.h"

using namespace std;


int main(){
    char input[50];
    cin >> input;
    char* x = strtok(input,",");
    char* y = strtok(NULL, ",");
    char* z = strtok(NULL, ",");
    cout << input << endl;
    Grid* g = Grid::deserialize(x);
    cout << *g << endl;
    Point* p1 = Point::deserialize(y);
    Point* p2 = Point::deserialize(z);
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