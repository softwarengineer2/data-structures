
#ifndef NODE_H_
#define NODE_H_

class Node {

public:
    int data;
    Node* next = nullptr;

    Node(int);
    
    ~Node();
};
#endif