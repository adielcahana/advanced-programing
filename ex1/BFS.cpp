//
// Created by ori on 14/11/16.
//

#include "BFS.h"

Node Node::getFather() {
    return this->father;
}

template <class T>
Node <T>::Node<T> (T info, Node father) : info(info), father(NULL) {}

queue <Node> findNeighbours(Node){

}

queue <Node> BFS:: findShortestWay(Graph graph, Node start, Node end){
    Node current = start;
    queue <Node> nodes;
    nodes.push(current);
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
                // check if visited
                for(int i = 0; i < this->markedNodes.size(); i++) {
                    if (temp.front() == markedNodes.at(i));
                    temp.pop();
                }
                nodes.push(temp.front());
                temp.pop();
            }
            current = nodes.front();
            nodes.pop();
        }
    }
return nodes;
}