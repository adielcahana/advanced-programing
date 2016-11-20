#include <iostream>
#include <ctime>
#include "Binary_tree.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        cout <<"not enough arguments" << endl;
        return 0;
    }
    else {
        Binary_tree *tree = new Binary_tree(0);
        tree->create_full_tree(stoi(argv[1]));
        clock_t start = clock();
        tree->dfs();
        clock_t end = clock();
        cout.precision(5);
        cout << "runtime: " << float( end - start ) /  CLOCKS_PER_SEC << " sec" << endl;
        delete tree;
        return 0;
    }
}