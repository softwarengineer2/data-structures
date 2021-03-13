#include <iostream>
#include "../include/doubly_linked_list.hpp"

void DoublyLinkedList::Traverse() {
    Node* tempPtr = head;
    while(tempPtr != NULL) {
        std::cout<<"Data : "<<tempPtr->data<<std::endl;
        tempPtr = tempPtr->next;
    }
}


void DoublyLinkedList::InsertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if(this->head != NULL) {
        newNode->next = this->head;
        this->head->prev = newNode;
    }
    this->head = newNode;
    size++;
}

void DoublyLinkedList::InsertAtLast(int data) {
    Node* lastNode = head;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    Node* newData = new Node(data);
    lastNode->next = newData;
    newData->prev = lastNode;
    size++;
}

void DoublyLinkedList::InsertAtPosition(int data, int position) {
    int counter = 0;
    if(position < 1 || position > size) {
        throw std::overflow_error("invalid position!");
    }
    Node* targetNode = head;
    Node* prevNode = NULL;
    Node* newNode = new Node(data);
    while(targetNode != NULL) {
        if(counter == position-1) {
            newNode->next = targetNode;
            if(prevNode == NULL) {
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
    Node* prevNode = NULL;
    while(targetNode != NULL) {
        if(counter == position-1) {
            if(prevNode == NULL) {
                head = targetNode->next;
            }
            else {
                prevNode->next = targetNode->next;
                if(prevNode->next != nullptr)
                    prevNode->next->prev = prevNode;
            }
            targetNode->prev = nullptr;
            targetNode->next = NULL;
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
    if(head!=NULL)
        delete head;
}