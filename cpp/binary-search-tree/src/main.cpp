#include <iostream>
#include "../include/binary_seach_tree.hpp"

using namespace std;

int main() {
    BinarySearchTree* binarySearchTree = new BinarySearchTree();
    binarySearchTree->Add(15);
    binarySearchTree->Add(10);
    binarySearchTree->Add(8);
    binarySearchTree->Add(12);
    binarySearchTree->Add(20);
    binarySearchTree->Add(16);
    binarySearchTree->Add(25);
    binarySearchTree->printInorder(binarySearchTree->root);
    cout<<endl;
    binarySearchTree->printPreorder(binarySearchTree->root);
    cout<<endl;
    binarySearchTree->printPostorder(binarySearchTree->root);
    cout<<endl;
    delete binarySearchTree;
    return 0;
}