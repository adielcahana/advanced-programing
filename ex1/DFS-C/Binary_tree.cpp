//
// Created by adi on 20/11/16.
//
#include "Binary_tree.h"
#include <cmath>

using namespace std;

Binary_tree::~Binary_tree(){
    if (!left) delete left;
    if (!right) delete right;
}

void Binary_tree::create_full_tree(int numOfLeaves){
    int height = (int) log2((double) numOfLeaves);
    this->full_tree(height);
}

void Binary_tree::full_tree(int height){
    static int number = 1;
    data = number;
    number++;
    if (height == 0) return;
    left = new Binary_tree(0);
    left->full_tree(height - 1);
    right = new Binary_tree(0);
    right->full_tree(height - 1);
}

void Binary_tree::dfs(){
    cout << this->data << endl;
    if (left != NULL) left->dfs();
    delete left;
    if (right != NULL) right->dfs();
    delete right;
}

