#include <iostream>
#include <algorithm>
#include "grid.h"

using namespace std;

int main(){
	vector<Point*> v;
	Grid* g = new Grid(6, 7, v);
	cout << *g << endl;
    Point* p1 = new Point(0,0);
    Point* p2 = new Point(2,4);
    stack <Point*, vector<Point*> >* route = g->get_route(p1,p2);
    while(!route->empty()){
        cout << *route->top() << endl;
        route->pop();
    }
//    for(int i= 0; i < 10; i++){
//        for(int j= 0; j < 10; j++){
//            cout << Point(i,j).hash() << " ";
//        }
//    }
}