#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Binary_tree.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        cout <<"not enough arguments" << endl;
        return 0;
    }
    else {
        Binary_tree *tree = new Binary_tree(0);
        tree->create_full_tree(atoi(argv[1]));
        tree->dfs();
        delete tree;
        return 0;
    }
}
