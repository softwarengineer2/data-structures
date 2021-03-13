#include <iostream>
#include "../include/linked_list.hpp"

void LinkedList::Traverse() {
    Node* tempPtr = head;
    while(tempPtr != NULL) {
        std::cout<<"Data : "<<tempPtr->data<<std::endl;
        tempPtr = tempPtr->next;
    }
}


void LinkedList::InsertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if(this->head != NULL)
        newNode->next = this->head;
    this->head = newNode;
    size++;
}

void LinkedList::InsertAtLast(int data) {
    Node* lastNode = head;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = new Node(data);
    size++;
}

void LinkedList::InsertAtPosition(int data, int position) {
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
    Node* prevNode = NULL;
    while(targetNode != NULL) {
        if(counter == position-1) {
            if(prevNode == NULL) {
                head = targetNode->next;
            }
            else {
                prevNode->next = targetNode->next;
            }
            targetNode->next = NULL;
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
    if(head!=NULL)
        delete head;
}