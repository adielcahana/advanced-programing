//
// Created by adi on 20/11/16.
//

#ifndef EX1_DFS_BINARY_TREE_H
#define EX1_DFS_BINARY_TREE_H

#include <iostream>

class Binary_tree {
private:
    int data;
    Binary_tree *right;
    Binary_tree *left;
    void full_tree(int height);
public:
    Binary_tree(int data) : data(data), left(NULL), right(NULL) {};
    ~Binary_tree();
    void setData(int data);
    void create_full_tree(int numOfLeaves);
    void dfs();
};

#endif //EX1_DFS_BINARY_TREE_H
