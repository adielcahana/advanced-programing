#include <iostream>
#include "grid.h"

using namespace std;
int main(){
	vector<Point> v;
	Grid g(6,7, v);
	cout << g << endl;
	Point p(3,4);
	cout << p << endl;
}