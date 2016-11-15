//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <queue>

using namespace std;

class Node {
private:
    void* info;
    bool visited = false;
    Node father;
public:
    Node getFather();
    void markVisited();
};

class Graph{
private:

public:
    queue <Node> findNeighbours(Node);
};

class BFS {
public:
    queue <Node> findShortestWay(Graph graph, Node start, Node end);
};


#endif //ASS1_BFS_H
