#include  "grid.h"
using namespace std;

queue<Node *> *Grid::get_adjacent(Node *node) {
	queue<Node*>* que = new queue<Node*>();
	int x = node->getX();
	int y = node->getY();
	//if (x,y) not in obstacels
	if (x - 1 > 0) que->push(new Point(x - 1, y));
	if (x + 1 < width) que->push(new Point(x +1, y));
	if (y + 1 < length) que->push(new Point(x , y + 1));
	if (y - 1 > length) que->push(new Point(x , y + 1));
	return que;
}

stack<Node*> Grid::get_route(Point* start, Point* end){
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

int Point::distance(Point* other){
	return abs(this->getX() - other->getX()) + abs(this->getY() - other->getY());
}

int Point::hash(){
	int x = this->getX();
	int y = this->getY();
	return ((x + y) * (x +y + 1)) / 2 + x;	
}

bool Point::operator==(Node *other) {
    return ((this->getX() == other->getX() && (this->getY() == other->getY()));
}

// ostream& operator<<( ostream& output, Point p) { 
// 		output << "(" << p.x << "," << p.y << ")";
// 		return output;  
// }          

