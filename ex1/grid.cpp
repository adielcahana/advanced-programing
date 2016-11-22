#include  "grid.h"
using namespace std;

queue<Point*>* Grid::get_adjacent(Point& point) {
	queue<Point*>* que = new queue<Point*>();
	int x = point.getX();
	int y = point.getY();
	//if (x,y) not in obstacels
	if (x - 1 > 0) que->push(new Point(x - 1, y));
    if (y + 1 < length) que->push(new Point(x , y + 1));
	if (x + 1 < width) que->push(new Point(x + 1, y));
	if (y - 1 > length) que->push(new Point(x , y - 1));
	return que;
}

stack<Point*> Grid::get_route(Point* start, Point* end){
	BFS bfs;
	return bfs.find_shortest_route(this, start, end);
}

Grid::~Grid(){
	obstacels.clear();
}

int Point::getX(){
	return this->x;
}

int Point::getY(){
	return this->y;
}

int Point::hash(){
	int x = this->getX();
	int y = this->getY();
	return ((x + y) * (x +y + 1)) / 2 + x;	
}

bool Point::operator!=(const Node &rhs) const {
    return false;
}

bool Point::operator==(const Node &rhs) const {
    return x == ((Point) rhs).getX() && y == ((Point) rhs).getY();
}


//bool Point::operator==(const Point& other) const {
//    return x == other.x && y == other.y;
//}
//
//bool Point::operator!=(const Point& other) const {
//    return !(other == *this);
//}

