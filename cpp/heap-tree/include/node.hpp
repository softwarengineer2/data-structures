
#ifndef NODE_H_
#define NODE_H_

class Node {

public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node()=default;
    Node(int data);
};
#endif