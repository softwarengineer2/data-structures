
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../include/node.hpp"

class LinkedList {

public:
    Node* head = nullptr;
    int length = 0;

    void Traverse();

    void InsertAtBeginning(int);
    void InsertAtLast(int);
    void InsertAtPosition(int, int);

    ~LinkedList();
};
#endif