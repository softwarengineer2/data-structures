#include <iostream>
#include "../include/circular_linked_list.hpp"

void CircularLinkedList::Traverse() {
    std::cout<<"CircularLinkedList::Traverse()"<<std::endl;
    Node* tempPtr = last->next;
    do {
        std::cout<<"Data : "<<tempPtr->data<<std::endl;
        tempPtr = tempPtr->next;
    }
    while(tempPtr != last->next);
}

void CircularLinkedList::InsertAtBeginning(int data) {
    std::cout<<"CircularLinkedList::InsertAtLast"<<std::endl;
    Node* newNode = new Node(data);
    if(last != NULL) {
        newNode->next = last->next;
        last->next = newNode;
    }
    else {
        newNode->next = newNode;
        last = newNode;
    }
    size++;
}

void CircularLinkedList::InsertAtLast(int data) {
    std::cout<<"CircularLinkedList::InsertAtLast"<<std::endl;
    Node* newNode = new Node(data);
    if(last != NULL) {
        newNode->next = last->next;
        last->next = newNode;
    }
    else {
        newNode->next = newNode;
    }
    last = newNode;
    size++;
}

void CircularLinkedList::InsertAtPosition(int data, int position) {
    int counter = 0;
    if(position < 1 || position > size) {
        throw std::overflow_error("invalid position!");
    }
    if(last == nullptr) {
        InsertAtLast(data);
    }
    else if(position == 1) {
        InsertAtBeginning(data);
    }
    else {
        Node* newNode = new Node(data);
        Node* prevNode = NULL;
        Node* targetNode = last->next;
        do {
            if(counter == position-1) {
                newNode->next = targetNode;
                prevNode->next = newNode;
                size++;
                break;
            }
            prevNode = targetNode;
            targetNode = targetNode->next;
            counter++;
        }
        while(targetNode != last->next);
    }
}

void CircularLinkedList::DeleteAtPosition(int position) {
    int counter = 0;
    if(position < 1 || position > size) {
        throw std::overflow_error("invalid position!");
    }
    if(last != nullptr) {
        Node* prevNode = NULL;
        Node* targetNode = last->next;
        do {
            if(counter == position-1) {
                if(targetNode == last)
                    last = prevNode;
                if(size == 1)
                    last = nullptr;
                prevNode->next = targetNode->next;
                targetNode->next = nullptr;
                delete targetNode;
                size--;
                break;
            }
            prevNode = targetNode;
            targetNode = targetNode->next;
            counter++;
        }
        while(targetNode != last->next);
    }
}

CircularLinkedList::~CircularLinkedList() {
    if(last!= nullptr) {
        Node* lastPtr = last->next;
        Node* tempPtr = last->next;
        Node* nextPtr = last->next;
        do {
            if(tempPtr == nullptr) {
                break;
            }
            else {
                nextPtr = tempPtr->next;
                if(tempPtr!=nullptr)
                    delete tempPtr;
            }
            tempPtr = nextPtr;
        }
        while(tempPtr != lastPtr);
    }
}