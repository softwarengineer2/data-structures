
#ifndef MAX_HEAP_TREE_H_
#define MAX_HEAP_TREE_H_
#include <iostream>
#include <vector>
#include "node.hpp"

class MaxHeapTree {
private:
    int Parent(int i);
    int Left(int i);
    int Right(int i);

public:
    Node* root;

    std::vector<int> vect = {-1};

    int size = 0;

    MaxHeapTree()=default;
    ~MaxHeapTree();

    bool IsEmpty() const;
    int GetMax();
    void Add(int data);

    void ShiftUp(int i);
    void ShiftDown(int i);
    int ExtractMax();

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