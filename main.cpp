#include <iostream>
#include "SplayTree.h"

int main() {
    SplayTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);
    tree.insert(35);

    tree.print();

    tree.remove(30);

    tree.print();


    return 0;
}
