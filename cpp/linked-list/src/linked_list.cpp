#include <iostream>
#include "../include/linked_list.hpp"

void LinkedList::Traverse() {
    Node* tempPtr = head;
    while(tempPtr != nullptr) {
        std::cout<<"Data : "<<tempPtr->data<<std::endl;
        tempPtr = tempPtr->next;
    }
}


void LinkedList::InsertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if(head != nullptr)
        newNode->next = head;
    head = newNode;
    size++;
}

void LinkedList::InsertAtLast(int data) {
    if(head == nullptr) {
        InsertAtBeginning(data);
    }
    else {
        Node* lastNode = head;
        while(lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = new Node(data);
        size++;
    }
}

void LinkedList::InsertAtPosition(int data, int position) {
    int counter = 0;
    if(position < 1 || position > size) {
        throw std::overflow_error("invalid position!");
    }
    Node* targetNode = head;
    Node* prevNode = nullptr;
    Node* newNode = new Node(data);
    while(targetNode != nullptr) {
        if(counter == position-1) {
            newNode->next = targetNode;
            if(prevNode == nullptr) {
                head = newNode;
            }
            else {
                prevNode->next = newNode;
            }
            size++;
            break;
        }
        prevNode = targetNode;
        targetNode = targetNode->next;
        counter++;
    }
}

void LinkedList::DeleteAtPosition(int position) {
    int counter = 0;
    if(position < 1 || position > size) {
        throw std::overflow_error("invalid position!");
    }
    Node* targetNode = head;
    Node* prevNode = nullptr;
    while(targetNode != nullptr) {
        if(counter == position-1) {
            if(prevNode == nullptr) {
                head = targetNode->next;
            }
            else {
                prevNode->next = targetNode->next;
            }
            targetNode->next = nullptr;
            delete targetNode;
            size--;
            break;
        }
        prevNode = targetNode;
        targetNode = targetNode->next;
        counter++;
    }
}

LinkedList::~LinkedList() {
    if(head!=nullptr)
        delete head;
}