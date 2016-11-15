#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "bfs.h"

using namespace std;


class Point: private Node{
	private:
		int x;
		int y;
	public:		
		int getX();
		int getY();
		bool operator ==(Point other);
		int distance(Point other);
		bool Point::hash();
		friend ostream &operator<<( ostream &output, Point p);
};

class Grid: private Graph{
	private:
		int length;
		int width;
		vector<Point> obstacels;
		queue<Point> get_adjacent(Point coordinate);		
	public:		
		queue<Point> get_route(Point start, Point end);
		friend ostream &operator<<( ostream &output, Grid g);
};