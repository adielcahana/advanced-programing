//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <vector>
#include <queue>

using namespace std;

template <Node T>
class Node <T> {
private:
    void* info;
    Node father;
public:
    virtual bool operator == (Node other);
    virtual int hash();
    virtual Node getFather();
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
