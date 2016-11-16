#include  "grid.h"
using namespace std;

queue<Point*>* Grid::get_adjacent(Point& coordinate){
        queue<Point*>* que = new queue<Point>*();
	int x = coordinate.getX();
	int y = coordinate.getY();
	//if (x,y) not in obstacels
	if (x - 1 > 0) que->push(new Point(x - 1, y)); 
	if (x + 1 < width) que->push(new Point(x +1, y));
	if (y + 1 < length) que->push(new Point(x , y + 1));
	if (y - 1 > length) que->push(new Point(x , y + 1));
	return que;
}

stack<Node> Grid::get_route(Point* start, Point* end){
	BFS bfs;
	return bfs.find_shortest_route(this, start, end);
}

// ostream& operator<<(ostream &output, Grid g) { 
// 	output << " ";
// 	for (int i = 0; i <= g.length; i++) output << i;
// 	output << endl << endl;		
// 	for (int i = 0; i < g.length; i++){
// 		output << i << " ";
// 		for (int j = 0; j < g.width; j++){
// 			/* if (new Point(i,j) in g.obstacles) {
// 				output << "x";			
// 				}*/
// 			output << "-";
// 		}
// 		output << endl;		
// 	}
// 	return output;            
// }


int Point::getX(){
	return this->x;
}

int Point::getY(){
	return this->y;
}

int Point::distance(Point* other){
	return abs(this->getX() - other.getX()) + abs(this->getY() - other.getY());
}

bool Point::operator ==(Point* other){
	if((this->getX() == other->getX()) && (this->getY() == other->getY())) return true;
	return false;	
}

int Point::hash(){
	int x = this->getX();
	int y = this->getY();
	return ((x + y) * (x +y + 1)) / 2 + x;	
}

// ostream& operator<<( ostream& output, Point p) { 
// 		output << "(" << p.x << "," << p.y << ")";
// 		return output;  
// }          

