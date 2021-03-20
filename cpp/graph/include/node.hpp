
#ifndef NODE_H_
#define NODE_H_

class Node {

public:
    int data;
    int weight;
    Node* next = nullptr;

    Node()=default;
    Node(int data, int weight=1);
    
    //~Node();
};
#endif