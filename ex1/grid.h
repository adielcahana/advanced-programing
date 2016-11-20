//
// Created by adi on 19/11/16.
//

#ifndef EX1_GRID_H
#define EX1_GRID_H


#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "BFS.h"

class Point{
private:
    int x;
    int y;
public:
    Point(int x, int y): x(x), y(y) {};
    Point(const Point& other): x(other.x), y(other.y) {}

    Point(int x);;
    int getX() const;
    int getY() const;
    int distance(Point *other);
    int hash();
        friend std::ostream &operator<<(std::ostream &output, const Point &p) {
        output << "(" << p.x << "," << p.y << ")";
        return output;
    }

    bool operator==(const Point &other) const;

    bool operator!=(const Point &other) const;
};

class Grid{
private:
    int length;
    int width;
    std::vector<Point *> obstacels;
public:
    Grid(int length, int width, std::vector<Point *> obstacels):length(length), width(width), obstacels(obstacels) {};
    ~Grid();
    std::stack<Point *, std::vector<Point *> > *get_route(Point *start, Point *end);
    std::stack <Point*, std::vector<Point*> >* get_adjacent(Point *coordinate);
    friend std::ostream &operator<<(std::ostream &output, const Grid &g) {
        output << "  ";
        for (int i = 0; i <= g.length; i++) output << i;
        output << std::endl;
        for (int i = g.length - 1; i >= 0; i--) {
            output << i << " ";
            for (int j = 0; j < g.width; j++) {
                /* if (new Point(i,j) in g.obstacles) {
                    output << "x";
                    }*/
                output << "-";
            }
            output << std::endl;
        }
        return output;
    }
};

#endif //EX1_GRID_H
