//
// Created by adi on 19/11/16.
//

#ifndef EX1_BFS_H
#define EX1_BFS_H

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include "grid.h"

template <class T>
class Edge {
private:
    T* data;
    Edge* father;

public:
    Edge(T* data): data(data),father(NULL){};
    ~Edge<T>();
    void setFather(Edge* father);
    Edge* getFather();
    T* getData();
    int hash();
    bool operator==(const Edge<T> &rhs) const;
    bool operator!=(const Edge<T> &rhs) const;
};

template <class T>
class Graph{
    T* data;
public:
    Graph(T* data): data(data){};
    template <class E>
    std::queue <Edge<E>*>* get_adjacent(Edge<E>* edge);
    ~Graph(){};
};

template <class E, class T>
class BFS {
private:
    std::vector<bool> visited;
//    std::bitset<200> visited;
public:
    BFS(E max_data);
    std::stack <E*, std::vector<E*> >* findShortestRoute(Graph<T>& graph, Edge<E>* start,Edge<E>* end);
    std::stack <E*, std::vector<E*> >* createRoute(Edge<E>* start,Edge<E>* end);
};

#endif //EX1_BFS_H
