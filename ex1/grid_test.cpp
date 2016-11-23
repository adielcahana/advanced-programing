#include <iostream>
#include <string>
#include "grid.h"

using namespace std;


int main(){
    char input[50];
    cin >> input;
    char* x = strtok(input,",");
    cout << input << endl;
    Grid* g = Grid::deserialize(x);
    PointComparator comparator;
    cout << *g << endl;
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(2,2);
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