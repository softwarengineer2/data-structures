#include <iostream>
#include "../include/node.hpp"

using namespace std;

int main() {
    const int N = 8;
    const int n = 6;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);

    return 0;
}