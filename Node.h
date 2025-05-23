#ifndef NODE_H
#define NODE_H

// Структура одного узла дерева
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int key);
};

#endif // NODE_H
