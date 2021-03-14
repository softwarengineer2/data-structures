#include <iostream>
#include "../include/doubly_linked_list.hpp"

void DoublyLinkedList::Traverse() {
    Node* tempPtr = head;
    while(tempPtr != nullptr) {
        std::cout<<"Data : "<<tempPtr->data<<std::endl;
        tempPtr = tempPtr->next;
    }
}


void DoublyLinkedList::InsertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if(head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    size++;
}

void DoublyLinkedList::InsertAtLast(int data) {
    if(head == nullptr) {
        InsertAtBeginning(data);
    }
    else {
        Node* lastNode = head;
        while(lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        Node* newData = new Node(data);
        lastNode->next = newData;
        newData->prev = lastNode;
        size++;
    }
}

void DoublyLinkedList::InsertAtPosition(int data, int position) {
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
            targetNode->prev = newNode;
            size++;
            break;
        }
        targetNode = targetNode->next;
        prevNode = targetNode->prev;
        counter++;
    }
}

void DoublyLinkedList::DeleteAtPosition(int position) {
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
                if(prevNode->next != nullptr)
                    prevNode->next->prev = prevNode;
            }
            targetNode->prev = nullptr;
            targetNode->next = nullptr;
            delete targetNode;
            size--;
            break;
        }
        targetNode = targetNode->next;
        prevNode = targetNode->prev;
        counter++;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    if(head!=nullptr)
        delete head;
}