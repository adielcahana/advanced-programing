#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BFS.h"

using namespace std;


class Point: private Node{
	private:
		int x;
		int y;
	public:
		Point(int x, int y): x(x), y(y) {};		
		int getX();
		int getY();
		bool operator ==(Point other);
		int distance(Point other);
		int hash();
		friend ostream &operator<<(ostream &output, const Point p);
};

class Grid: private Graph{
	private:
		int length;
		int width;
		vector<Point> obstacels;
		queue<Point> get_adjacent(Point coordinate);		
	public:	
		Grid(int length, int width, vector<Point> obstacels): length(length), width(width), obstacels(obstacels){};
		stack<Point> get_route(Point start, Point end);
		friend ostream &operator<<(ostream &output, const Grid g);
};