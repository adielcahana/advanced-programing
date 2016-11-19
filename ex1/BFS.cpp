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
bool Edge<T>:: operator==(Edge<T> other){
    return *(this->data) == *(other.data);
}



template <class E,class T>
stack <E*, vector<E*> >* BFS<E,T>::findShortestRoute(Graph<T>& graph, Edge<E>* start,Edge<E>* end){
    int x = 0 ,y = 0;
    std::bitset<10000> visited;
    Edge<E>* current = start;
    queue <Edge<E>*> edges;
    stack <E*, vector<E*> >* route = NULL;
    edges.push(current);
    while (!edges.empty()) {
        cout << x++ << endl;
        if(*end == *current){
            route = this->createRoute(start, current);
            while (!edges.empty()){
                delete edges.front();
                edges.pop();
            }
            delete end;
        }
        else {
	        cout << "inside else" << endl;
            queue <Edge<E>*>* adjacents = graph.get_adjacent(current);
            //pop current from edges
            edges.pop();
            visited.set(current->hash());
            for(int i =0; i < adjacents->size(); i++) {
	                cout << "inside 2nd while" << endl;
                    cout << "     " << y++ << endl;
                    Edge<E> *temp = adjacents->front();
                    adjacents->pop();
                    // check if visited
                    if (visited[temp->hash()] == 1) {
                        delete temp;
                        continue;
                    }
                    temp->setFather(current);
                    edges.push(temp);
                }
            y = 0;
            delete adjacents;
        }
            current = edges.front();
        }
    cout << "done" << endl;
    return route;
    }



template <class T>
template <class E>
queue<Edge<E>*>* Graph<T>:: get_adjacent(Edge<E>* edge){
    queue <E*>* que = this->data->get_adjacent(edge->getData());
    queue <Edge<E>*>* adjacents = new queue <Edge<E>*>();
    Edge<E>* temp = NULL;
    while(!que->empty()){
        temp = new Edge<E>(que->front());
        que->pop();
        adjacents->push(temp);
    }
    delete que;
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
    return stck;
}

template class BFS<Point,Grid>;


