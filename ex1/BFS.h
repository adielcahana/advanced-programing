//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


class Node {
private:
	//friend BFS;
    Node* father;
public:
    virtual bool operator ==(Node* other)=0;
    virtual int hash()=0;
    void setFather(Node* ather);
    Node* getFather();
};

class Graph{
public:
  virtual queue <Node*> get_adjacent(Node)=0;
};

class BFS {
private:
    vector <Node*> markedNodes;
public:
    stack <Node*> find_shortest_route(Graph* graph, Node* start, Node* end);
    stack <Node*> createRoute(Node* end ,Node* start);
};


#endif //ASS1_BFS_H
