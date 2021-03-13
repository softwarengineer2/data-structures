
#ifndef NODE_H_
#define NODE_H_

class Node {

public:
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int);
    
    ~Node();
};
#endif