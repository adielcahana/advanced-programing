//
// Created by ori on 14/11/16.
//

#include "BFS.h"
using namespace std;

template <class T>
Edge<T>::~Edge() {
    delete data;
}

template <class T>
Edge<T>* Edge<T>::getFather() {
    return this->father;
}

template <class T>
void Edge<T>:: setFather(Edge<T>* father){
    this->father = father;
}

template <class T>
T* Edge<T>::getData(){
    return data;
}
template <class T>
int Edge<T>::hash(){
    return data->hash();
}

template <class T>
bool Edge<T>::operator==(const Edge<T> &rhs) const {
    return *data == *rhs.data;
}

template <class T>
bool Edge<T>::operator!=(const Edge<T> &rhs) const {
    return !(rhs == *this);
}

template <class E,class T>
BFS<E,T>::BFS(E max_data) {
    visited.resize(max_data.hash());
}

template <class E,class T>
stack <E*, vector<E*> >* BFS<E,T>::findShortestRoute(Graph<T>& graph, Edge<E>* start,Edge<E>* end){
    Edge<E>* current = start;
    queue <Edge<E>*> edges;
    stack <E*, vector<E*> >* route = NULL;
    visited[start->hash()] = 1;
    edges.push(current);
    while (!edges.empty()) {
        if(*end == *current){
            route = this->createRoute(start, current);
            // realese all the alloceted memory (not good)
            while (!edges.empty()){
                delete edges.front();
                edges.pop();
            }
        }
        else {
            queue <Edge<E>*>* adjacents = graph.get_adjacent(current);
            //pop current from edges
            edges.pop();
            for(int i =0; i <= adjacents->size(); i++) {
                    Edge<E> *temp = adjacents->front();
                    adjacents->pop();
                    // check if visited
                    if (visited[temp->hash()] == 1) {
                        delete temp;
                        continue;
                    }
//                    cout << *temp->getData() << endl;
                    visited[temp->hash()] = 1;
                    temp->setFather(current);
                    edges.push(temp);
                }
            delete adjacents;
        }
            current = edges.front();
        }
    delete end;
    return route;
    }



template <class T>
template <class E>
queue<Edge<E>*>* Graph<T>:: get_adjacent(Edge<E>* edge){
    stack <E*, std::vector<E*> >* stck = this->data->get_adjacent(edge->getData());
    queue <Edge<E>*>* adjacents = new queue <Edge<E>*>();
    Edge<E>* temp = NULL;
    while(!stck->empty()){
        temp = new Edge<E>(stck->top());
        stck->pop();
        adjacents->push(temp);
    }
    delete stck;
    return adjacents;
}


template <class T, class E>
stack <T*, vector<T*> >* BFS<T, E>::createRoute(Edge<T>* start ,Edge<T>* end){
    Edge<T>* temp = end;
    stack <T*, vector<T*> >* stck = new stack<T*, vector<T*> >();
    while (!(*temp == *start)){
        stck->push(new Point(*temp->getData()));
        temp = temp->getFather();
    }
    stck->push(new Point(*start->getData()));
    return stck;
}

template class BFS<Point,Grid>;


