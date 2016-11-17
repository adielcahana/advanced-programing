//
// Created by ori on 14/11/16.
//

#include "../header/BFS.h"
template <class T>
Edge<T>::~Edge() {
//    if (father != NULL) delete father;
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
bool Edge<T>:: operator==(Edge<T> other){
    return *(this->data) == *(other.data);
}

template <class T>
T* Edge<T>::getData(){
    return data;
}

template <class T>
template <typename E>
queue<Edge<E>*>* Graph<T>:: get_adjacent(Edge<E>* edge){
    queue <E*>* que = this->data->get_adjacent(edge->getData());
    queue <Edge<E>*>* adjacents = new queue <Edge<E>*>();
    Edge<E>* temp = NULL;
    while(!que->empty()){
        temp = que->front();
        temp->setFather(edge);
        adjacents->push(temp);
    }
    delete que;
    return adjacents;
}
template <class E>
template <typename T>
stack <E*, vector<E*> >* BFS<E>:: find_shortest_route(Graph<T>& graph, Edge<E>* start,Edge<E>* end){
    Edge<E>* current = start;
    queue <Edge<E>*> edges;
    stack <E*, vector<E*> >* stck = NULL;
    edges.push(current);
    while (!edges.empty()) {
        if(*current == *end){
            while (!edges.empty()){
                edges.pop();
            }
            stck = this->createRoute(start, end);
        }
        else {
            queue <Edge<E>*>* adjacents = graph.get_adjacent(current);
            for(int i =0; i < adjacents->size(); i++) { {
                Edge<E> *temp = adjacents->front();
                // check if visited
                for (int j = 0; j < visited.size(); j++) {
                    if (adjacents->front() == visited.at(j)) {
                        adjacents->pop();
                        delete temp;
                        break;
                    }
                }
                edges.push(temp);
                adjacents->pop();
            }
            visited.push_back(current);
            }
            current = edges.front();
        }
    }
    return stck;
}

template <class T>
stack <T*, vector<T*> >* BFS<T>::createRoute(Edge<T>* start ,Edge<T>* end){
    Edge<T>* temp = end;
    stack <T*, vector<T*> >* stck = new stack<T*, vector<T*> >();
    while (!(*temp == *start)){
        stck->push(temp->getData());
        temp = temp->getFather();
    }
    return stck;
}


