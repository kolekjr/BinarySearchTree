#include <iostream>
#include "btree.h"

using namespace tree;

int main(int argc, char** args)
{
    BinarySearchTree<int> btree;
    btree.insert(10);
    btree.insert(120);
    btree.insert(1);
    btree.insert(13);
    btree.printTree();
    // BinarySearchTree<int> btree1;
    // int a{10};
    // btree.insert(a);
    // int b{120};
    // btree.insert(b);
    // int c{1};
    // btree.insert(c);
    // int d{13};
    // btree.insert(d);
    return 0;
}