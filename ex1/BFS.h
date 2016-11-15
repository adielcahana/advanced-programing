//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <vector>
#include <queue>

using namespace std;


class Node {
private:
    Node father;
public:
    Node(const Node &father);
    virtual bool operator ==(Node other);
    virtual int hash();
    Node getFather();
};

class Graph{
public:
    virtual queue <Node> get_adjacent(Node);
};

class BFS {
private:
    vector <Node> markedNodes;
public:
    queue <Node> find_shortest_route(Graph graph, Node start, Node end);
};


#endif //ASS1_BFS_H
