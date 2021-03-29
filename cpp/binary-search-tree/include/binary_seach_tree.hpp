
#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <queue>
#include "node.hpp"

class BinarySearchTree {

public:
    Node* root;

    int totalNodes = 0;

    BinarySearchTree()=default;
    ~BinarySearchTree();

    void Add(int data);
    void printPostorder(Node* node);
    void printPreorder(Node* node);
    void printInorder(Node* node);
};
#endif