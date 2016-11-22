//
// Created by ori on 14/11/16.
//

#include <stack>
#include "BFS.h"

Node* Node::getFather() {
    return this->father;
}

void Node:: setFather(Node *father){
    this->father = father;
}

vector <Node*>* BFS::find_shortest_route(Graph* graph, Node* start, Node* end){
    Node* current = start;
    queue <Node*> nodes;
    vector <Node*>* route;
    queue <Node*>* adjacents = NULL;
    Node* temp = NULL;
    nodes.push(current);
    while (!nodes.empty()) {
        if(*current == *end){
            while (!nodes.empty()){
                nodes.pop();
            }
            route = this->createRoute(start, end);
        }
        else {
            adjacents = graph->get_adjacent(current);
            while(!adjacents->empty()) {
                // check if visited
                temp = adjacents->front();
                if (visited[temp->hash()] == 1) {
                    delete adjacents->front();
                    adjacents->pop();
                    continue;
                }
                visited[temp->hash()] = 1;
                nodes.push(temp);
                adjacents->pop();
            }
            current = nodes.front();
            nodes.pop();
        }
    }
    return route;
}

vector <Node*>* BFS::createRoute(Node* start ,Node* end){
    Node* temp = end;
    vector <Node*>* route = new vector<Node*>()   ;
    while (!(*temp == *start)){
        route->push_back(temp);
        temp = temp->getFather();
    }
    return route;
}
