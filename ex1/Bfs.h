//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
private:
	//friend Bfs;
    Node* father;
    bool inRoute;
public:
	Node(): father(NULL), inRoute(false){};
    virtual int hash()= 0;
    void setFather(Node* father);
    void setInRoute();
    bool isInRoute();
    Node* getFather();
};

class NodeComparator {
    public:
        virtual bool equals(const Node* n1, const Node* n2) const = 0;
};

class Graph{
public:
	~Graph(){};
  	virtual queue<Node*>* getAdjacent(const Node *node)= 0;
};


class Bfs {
private:
    std::vector<bool> visited;
    vector<Node*>* createRoute(Node* end ,Node* start, NodeComparator* comparator);
public:
    Bfs(Node* maxNode);
    vector<Node*>* find_shortest_route(Graph* graph, Node* start, Node* end, NodeComparator* comparator);
};

#endif //ASS1_BFS_H
