#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BFS.h"

using namespace std;


class Point: public Node{
	private:
		int x;
		int y;
	public:
		Point(int x, int y): x(x), y(y) {};	
		int getX();
		int getY();

		int hash();
		friend ostream& operator<<( ostream& output,const Point& p) { 
			output << "(" << p.x << "," << p.y << ")";
			return output; 
		}
//        bool operator==(const Point &other) const;
//        bool operator!=(const Point &other) const;


        virtual bool operator!=(const Node &rhs) const;
        virtual bool operator==(const Node &rhs) const;
//      ostream &operator<<(ostream &output, const Point& p);
};

class Grid: public Graph{
	private:
		int length;
		int width;
		vector<Point*> obstacels;
	public:	
		Grid(int length, int width, vector<Point*> obstacels):length(length), width(width), obstacels(obstacels){};
		~Grid();
		stack<Node*> get_route(Point* start, Point* end);
		queue<Point*>* get_adjacent(Point& point);
		friend ostream& operator<<(ostream &output, const Grid& g) { 
			output << " ";
			for (int i = 0; i <= g.length; i++) output << i;
			output << endl << endl;		
			for (int i = 0; i < g.length; i++){
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
//ostream &operator<<(ostream &output, const Grid& g);
};
