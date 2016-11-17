//
// Created by ori on 14/11/16.
//

#ifndef ASS1_BFS_H
#define ASS1_BFS_H

#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

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
    bool operator==(Edge<T> other);
};

template <class T>
class Graph{
    T* data;
public:
    Graph(T* data): data(data){};
    template <typename E>
    queue <Edge<E>*>* get_adjacent(Edge<E>* edge);
    ~Graph(){};
};

template <class E>
class BFS {
private:
    vector <Edge<E>*> visited;
public:
    template <typename T>
    stack <E*, vector<E*> >* find_shortest_route(Graph<T>& graph, Edge<E>* start,Edge<E>* end);
    stack <E*, vector<E*> >* createRoute(Edge<E>* start,Edge<E>* end);
};


#endif //ASS1_BFS_H
