#include  "grid.h"
using namespace std;

queue<Node*>* Grid::get_adjacent(const Node* point) {
	queue<Node*>* adjacents = new queue<Node*>();
	int x = ((Point*) point)->getX();
	int y = ((Point*) point)->getY();
	//verify which are Point's neighbors and add them to adjacents
	if (x - 1 >= 0) adjacents->push(new Point(x - 1, y));
	if (y + 1 < length) adjacents->push(new Point(x , y + 1));
	if (x + 1 < width) adjacents->push(new Point(x + 1, y));
	if (y - 1 >= 0) adjacents->push(new Point(x , y - 1));
	return adjacents;
}

vector<Point*>* Grid::get_route(Point* start, Point* end){
    if (!isInGrid(start) || !isInGrid(end)) throw "get_route args are out of bounds!";
	//create max point availble in the grid, which has the highest hash value
    Node* maxPoint= new Point(width, length);
	//send max point to bfs, in order to allocate a large enough hash table
	BFS bfs(maxPoint);
    delete maxPoint;
    PointComparator comparator;
	return (vector<Point*>*) bfs.find_shortest_route(this, start, end, &comparator);
}

bool Grid::isInGrid(Point* p){
    int x = p->getX();
    int y = p->getY();
	//verify that x and y are between valid values of grid 
    return x >= 0 && x < width && y >= 0 && y < length;
}

Grid* Grid::deserialize(char* s){
    Point* maxPoint = Point::deserialize(s);
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
	//map (x,y) to an integer number
	return ((x + y) * (x +y + 1)) / 2 + x;	
}

bool Point::operator==(const Point &other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return !(other == *this);
}

Point* Point::deserialize(char* s){
    char* x = strtok(s,"_");
    char* y = strtok(NULL, "_");
    return new Point(atoi(x), atoi(y));
}

bool PointComparator::equals(const Node *n1, const Node *n2) const {
// downcast to Point, in order to use Point '==' operator
    return   *(Point*) n1 == *(Point*) n2;
}
