
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../include/node.hpp"

class Stack {

public:
    Node* top = nullptr;
    int size = 0;

    void Push(int);
    int Pop();
    int Top();
    bool IsEmpty();

    ~Stack();
};
#endif