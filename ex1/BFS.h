//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <vector>
#include <queue>

using namespace std;

template <class T>
class Node {
private:
    Node father;
public:

    Node(const Node &father);

    virtual bool operator == (Node other);
    virtual int hash();
    Node getFather();
};

class Graph{
private:

public:
    queue <Node> findNeighbours(Node);
};

class BFS {
private:
    vector <Node> markedNodes;
public:
    queue <Node> findShortestWay(Graph graph, Node start, Node end);
};


#endif //ASS1_BFS_H
