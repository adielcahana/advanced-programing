#include <iostream>
#include "grid.h"

using namespace std;


int main(){
	vector<Point*> v;
	Grid* g =new Grid(6, 7, v);
	cout << g << endl;
	Point* p = new Point(3,4);
	cout << p << endl;
}