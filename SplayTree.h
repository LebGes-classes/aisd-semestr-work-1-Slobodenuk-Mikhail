#ifndef UNTITLED1_SPLAYTREE_H
#define UNTITLED1_SPLAYTREE_H
#include "Node.h"

class SplayTree {
private:
    Node* root;

    Node* rightRotate(Node* x);
    Node* leftRotate(Node* x);
    Node* splay(Node* root, int key);

    void inorder(Node* node);

public:
    SplayTree();
    ~SplayTree();

    void insert(int key);
    void remove(int key);
    bool search(int key);
    void print();

    void destroyTree(Node* node);
};


#endif //UNTITLED1_SPLAYTREE_H
