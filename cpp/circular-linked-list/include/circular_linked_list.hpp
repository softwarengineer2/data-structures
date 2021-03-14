
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "../include/node.hpp"

class CircularLinkedList {

public:
    Node* last = nullptr;
    int size = 0;

    void Traverse();
    void InsertAtBeginning(int);
    void InsertAtLast(int);
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);

    ~CircularLinkedList();
};
#endif