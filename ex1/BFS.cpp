//
// Created by ori on 14/11/16.
//

#include <queue>
#include "BFS.h"

using namespace std;

void Node::markVisited() {
    this->visited = true;
}

Node Node::getFather() {
    return this->father;
}

queue <Node> findNeighbours(Node){

}

queue <Node> findShortestWay(Graph graph, Node start, Node end){
    Node current = start;
    start.markVisited();
    queue <Node> nodes;
    while (!nodes.empty()) {
        if(&current == &end){
            while (!nodes.empty()){
                nodes.pop();
            }
            while (&current != &start) {
                nodes.push(current);
                current = current.getFather();
            }
        }
        else {
            queue <Node> temp = graph.findNeighbours(current);
            while(!temp.empty()) {
                nodes.push(temp.front());
                temp.pop();
            }
            current = nodes.front();
            nodes.pop();
            current.markVisited();
        }
    }
return nodes;
}