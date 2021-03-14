
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../include/node.hpp"

class Stack {

public:
    Node* front = nullptr;
    Node* rear = nullptr;
    int size = 0;

    void Enqueue(int);
    int Dequeue();
    int Rear();
    int Front();
    bool IsEmpty();

    ~Stack();
};
#endif