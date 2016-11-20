#include "grid.h"
using namespace std;

Grid::~Grid(){
    obstacels.clear();
}

int Point::getX() const{
    return this->x;
}

int Point::getY() const{
    return this->y;
}

int Point::distance(Point* other){
    return abs(this->getX() - other->getX()) + abs(this->getY() - other->getY());
}

int Point::hash(){
    int x = this->getX();
    int y = this->getY();
    return (((x + y) * (x + y + 1)) / 2) + x;
}

bool Point::operator==(const Point &other) const {
    return x == other.x &&
           y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return !(other == *this);
}

stack <Point*, vector<Point*> >* Grid::get_adjacent(Point *node) {
    stack <Point*, vector<Point*> >* adjacent = new stack <Point*, vector<Point*> >();
	int x = node->getX();
	int y = node->getY();
	//if (x,y) not in obstacels
	if (x - 1 >= 0) adjacent->push(new Point(x - 1, y));
    if (y + 1 < length) adjacent->push(new Point(x , y + 1));
	if (x + 1 < width) adjacent->push(new Point(x + 1, y));
	if (y - 1 >= 0) adjacent->push(new Point(x , y - 1));
	return adjacent;
}

stack <Point*, vector<Point*> >* Grid::get_route(Point* start, Point* end){
	BFS<Point,Grid> bfs(Point(width, length));
    Graph<Grid> graph(this);
    return bfs.findShortestRoute(graph, new Edge<Point>(start), new Edge<Point>(end));
}




