//
// Created by ori on 14/11/16.
//

#include <stack>
#include "BFS.h"

Node Node::getFather() {
    return this->father;
}

void Node:: setFather(Node &father){
    this->father = father;
}

stack <Node> BFS::find_shortest_route(Graph graph, Node start, Node end){
    Node current = start;
    queue <Node> nodes;
    stack <Node> st;
    nodes.push(current);
    while (!nodes.empty()) {
        if(&current == &end){
            while (!nodes.empty()){
                nodes.pop();
            }
            st = this->createRoute(start, end);
        }
        else {
            queue <Node> temp = graph.get_adjacent(current);
            while(!temp.empty()) {
                // check if visited
                for(int i = 0; i < this->markedNodes.size(); i++) {
                    if (temp.front() == markedNodes.at(i));
                    temp.pop();
                }
                nodes.push(temp.front());
                markedNodes.push_back(current);
                temp.pop();
            }
            current = nodes.front();
            nodes.pop();
        }
    }
return st;
}

stack <Node> createRoute(Node start ,Node end){
    Node temp = end;
    stack <Node> st;
    while(&temp != &start){
        st.push(temp);
        temp = temp.getFather();
    }
    return st;
}