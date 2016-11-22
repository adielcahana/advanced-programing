#include  "grid.h"
using namespace std;

queue<Node*>* Grid::get_adjacent(const Node* point) {
	queue<Node*>* que = new queue<Node*>();
	int x = ((Point*) point)->getX();
	int y = ((Point*) point)->getY();
	//if (x,y) not in obstacels
	if (x - 1 >= 0) que->push(new Point(x - 1, y));
    if (y + 1 < length) que->push(new Point(x , y + 1));
	if (x + 1 < width) que->push(new Point(x + 1, y));
	if (y - 1 >= 0) que->push(new Point(x , y - 1));
	return que;
}

vector<Point*>* Grid::get_route(Point* start, Point* end){
    if (!isInGrid(start) || !isInGrid(end)) throw "get_route args are out of bounds!";
    Node* maxPoint= new Point(width, length);
	BFS bfs(maxPoint);
    delete maxPoint;
    PointComparator comparator;
	return (vector<Point*>*) bfs.find_shortest_route(this, start, end, &comparator);
}

bool Grid::isInGrid(Point* p){
    int x = p->getX();
    int y = p->getY();
    return x >= 0 && x < width && y >= 0 && y < length;
}

static Grid* Grid::deserialize(char* s){
    Point* maxPoint = Point.deserialize(s);
    Grid* g = new Grid(maxPoint->getX(),maxPoint->getY());
    delete maxPoint;
    return g;
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

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return !(other == *this);
}

static Point* Point::deserialize(char* s){
    char* x = strtok(s,"_");
    char* y = strtok(NULL, "_");
    return new Point(atoi(x), atoi(y));
}

//bool Point::operator==(const Point& other) const {
//    return x == other.x && y == other.y;
//}
//
//bool Point::operator!=(const Point& other) const {
//    return !(other == *this);
//}

bool PointComparator::equals(const Node *n1, const Node *n2) const {
    return   *(Point*) n1 == *(Point*) n2;
}
