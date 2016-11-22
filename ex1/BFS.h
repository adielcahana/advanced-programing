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
	Node(): father(NULL){};
    virtual int hash()= 0;
    void setFather(Node* father);
    Node* getFather();
    virtual bool operator==(const Node &rhs) const = 0;
    virtual bool operator!=(const Node &rhs) const = 0;
};

class Graph{
public:
	~Graph(){};
  	virtual queue<Node*>* get_adjacent(Node* node)= 0;
};

class BFS {
private:
    std::vector<bool> visited;
public:
    vector<Node*>* find_shortest_route(Graph* graph, Node* start, Node* end);
    vector<Node*>* createRoute(Node* end ,Node* start);
};

#endif //ASS1_BFS_H
