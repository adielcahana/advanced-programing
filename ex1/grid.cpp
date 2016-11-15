#include  "grid.h"

//check what assgining obst does
Grid::Grid(int length, int width, vector<Point> obstacels): length(length), width(width), obstacels(obstacels){};

queue<Point> Grid::get_adjacent(Point coordinate){
	queue<Point> que = new queue<Point>();
	int x = point.getX();
	int y = point.getY();
	//if (x,y) not in obstacels
	if (x - 1 > 0) que.push(new Point(x - 1, y)); 
	if (x + 1 < width) que.push(new Point(x +1, y));
	if (y + 1 < length) que.push(new Point(x , y + 1));
	if (y - 1 > length) que.push(new Point(x , y + 1));
	return queue;
}

queue<Point> Grid::get_route(Point start, Point end){
	BFS bfs = new BFS();
	return bfs.find_shortest_route(this, start, end);
}

friend ostream &operator<<( ostream &output, Grid g) { 
	output << " ";
	for (int i = 0; i <= g.length; i++) output << i;
	output << endl << endl;		
	for (int i = 0; i < g.length; i++){
		output << i << " ";
		for (int j = 0; j < g.width; j++){
			/* if (new Point(i,j) in g.obstacles) {
				output << "x";			
				}*/
			output << "-" << p.x << "," << p.y << ")";	
		}
		output << endl;		
	}
	return output;            
}

Point::Point(int x, int y): x(x), y(y) {};
int Point::getX(){
	return this.x;
}

Point::Point(int x, int y) x(x), y(y) {};

int Point::getY(){
	return this.y;
}

int Point::distance(Point other){
	return abs(this.getX() - other.getX()) + abs(this.getY() - other.getY());
}

bool Point::operator ==(Point other){
	if((this.getX() == this.getY) && (this.getY() == other.getY())) return 1;
	return 0;	
}

bool Point::hash(){
	int x = this.getX();
	int y = this.getY();
	return ((x + y) * (x +_y + 1)) / 2 + n;	
}

friend ostream &operator<<( ostream &output, Point p ) { 
		output << "(" << p.x << "," << p.y << ")";
		return output;            
}
