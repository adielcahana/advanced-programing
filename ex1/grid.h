#ifndef ASS1_GRID_H
#define ASS1_GRID_H

#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BFS.h"

using namespace std;


class Point{
	private:
		int x;
		int y;
	public:
		Point(int x, int y): x(x), y(y) {};	
		int getX();
		int getY();
		int distance(Point* other);
		int hash();
        bool operator==(Point *other);
		friend ostream& operator<<( ostream& output,const Point& p) { 
			output << "(" << p.x << "," << p.y << ")";
			return output; 
		}
};

class Grid{
	private:
		int length;
		int width;
		vector<Point*> obstacels;
	public:	
		Grid(int length, int width, vector<Point*> obstacels):length(length), width(width), obstacels(obstacels){};
		~Grid();
        stack <Point*, vector<Point*> >* get_route(Point* start, Point* end);
		queue <Point*>* get_adjacent(Point *coordinate);
		friend ostream& operator<<(ostream &output, const Grid& g) { 
			output << "  ";
			for (int i = 0; i <= g.length; i++) output << i;
			output << endl;
			for (int i = g.length - 1; i >= 0; i--){
				output << i << " ";
				for (int j = 0; j < g.width; j++){
					/* if (new Point(i,j) in g.obstacles) {
						output << "x";			
						}*/
					output << "-";
				}
				output << endl;		
			}
			return output;            
		}
};


#endif //ASS1_GRID_H