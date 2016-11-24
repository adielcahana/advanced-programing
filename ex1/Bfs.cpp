//
// Created by ori on 14/11/16.
//

#include "Bfs.h"

Node* Node::getFather() {
    return this->father;
}

void Node::setFather(Node *father){
    this->father = father;
}

void Node::setInRoute(){
    inRoute = true;
}

bool Node::isInRoute(){
    return inRoute;
}

Bfs::Bfs(Node* maxNode){
    visited.resize(maxNode->hash());
}

vector <Node*>* Bfs::find_shortest_route(Graph* graph, Node* start, Node* end, NodeComparator* comparator){
    vector <Node*> garbage;
    Node* current = start;
    queue <Node*> nodes;
    queue <Node*>* adjacents = NULL;
    vector <Node*>* route = NULL;
    Node* temp = NULL;
    nodes.push(current);
    while (!nodes.empty()) {
        nodes.pop();
        if(comparator->equals(current,end)){
            route = this->createRoute(start, current, comparator);
            while (!nodes.empty()){
                temp = nodes.front();
                delete temp;
                nodes.pop();
            }
//            break;
        }
        else {
            adjacents = graph->getAdjacent(current);
            while(!adjacents->empty()) {
                // check if visited
                temp = adjacents->front();
                if (visited[temp->hash()] == 1) {
                    delete temp;
                    adjacents->pop();
                    continue;
                }
                visited[temp->hash()] = 1;
                temp->setFather(current);
                nodes.push(temp);
                adjacents->pop();
            }
            delete adjacents;
            garbage.push_back(current);
            current = nodes.front();
        }
    }
    //realse unusable data

    for(int i = 0; i < garbage.size(); i++){
        temp = garbage.at(i);
        if(!temp->isInRoute()) {
            delete temp;
        }
    }
    return route;
}

vector <Node*>* Bfs::createRoute(Node* start ,Node* end, NodeComparator* comparator){
    Node* temp = end;
    vector <Node*>* route = new vector<Node*>();
    while (!comparator->equals(temp, start)){
        temp->setInRoute();
        route->push_back(temp);
        temp = temp->getFather();
    }
    start->setInRoute();
    route->push_back(start);
    reverse(route->begin(), route->end());
    return route;
}
