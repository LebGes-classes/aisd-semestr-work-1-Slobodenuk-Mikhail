#include <iostream>
#include "SplayTree.h"

using namespace std;

SplayTree::SplayTree() : root(nullptr) {}

SplayTree::~SplayTree() {
    destroyTree(root);
}

void SplayTree::destroyTree(Node* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

Node* SplayTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node* SplayTree::leftRotate(Node* y) {
    Node* x = y->right;
    y->right = x->left;
    x->left = y;
    return x;
}

Node* SplayTree::splay(Node* root, int key) {
    if (!root || root->key == key)
        return root;

    // левое поддеревол
    if (key < root->key) {
        if (!root->left) return root;
        // zigzig
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // zigzag
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }
        return (root->left == nullptr) ? root : rightRotate(root);
    }
    
    // правое поддерево
    else {
        if (!root->right) return root;

        // zagzag
        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // zagzig
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

void SplayTree::insert(int key) {
    if (!root) {
        root = new Node(key);
        return;
    }

    root = splay(root, key);

    if (root->key == key) return;

    Node* newNode = new Node(key);

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    root = newNode;
}

void SplayTree::remove(int key) {
    if (!root) return;

    root = splay(root, key);

    if (root->key != key) return;

    Node* temp;
    if (!root->left) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    delete temp;
}

bool SplayTree::search(int key) {
    root = splay(root, key);
    return root && (root->key == key);
}

void SplayTree::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void SplayTree::print() {
    cout << "In-order: ";
    inorder(root);
    cout << endl;
}
