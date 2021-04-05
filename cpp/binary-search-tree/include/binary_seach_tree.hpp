
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
    Node* Search(int data);
    Node* Delete(Node* node, int data);
    Node* FindMin(Node* node);
    int MaxDepth(Node* node);
    int MinDepth(Node* node);
    void DeleteTree(Node* node);
    void printPostorder(Node* node);
    void printPreorder(Node* node);
    void printInorder(Node* node);
};
#endif