#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
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
        bool operator==(const Point &rhs) const;
        bool operator!=(const Point &rhs) const;
        static Point* deserialize(char* s)
        friend ostream& operator<<( ostream& output,const Point& p) {
            output << "(" << p.x << "," << p.y << ")";
            return output;
    }
};

class PointComparator: public NodeComparator{
public:
    virtual bool equals(const Node *n1, const Node *n2) const;
};

class Grid: public Graph{
	private:
		int length;
		int width;
        bool isInGrid(Point* p);
	public:
		Grid(int width, int length): length(length), width(width) {};
		vector<Point*>* get_route(Point* start, Point* end);
		queue<Node*>* get_adjacent(const Node* point);
        static Grid* deserialize(char* s);
		friend ostream& operator<<(ostream &output, const Grid& g) {
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
            output << "  ";
            for (int i = 0; i < g.width; i++) output << i;
			return output;

		}
};
