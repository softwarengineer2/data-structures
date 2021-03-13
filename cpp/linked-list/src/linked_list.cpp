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
    length++;
}

void LinkedList::InsertAtLast(int data) {
    Node* lastNode = head;
    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = new Node(data);
    length++;
}

void LinkedList::InsertAtPosition(int data, int position) {
    int counter = 0;
    if(position > length) {
        throw std::overflow_error("position is wrong!");
    }
    Node* targetNode = head;
    Node* newNode = new Node(data);
    while(targetNode != NULL && counter < position) {
        if(counter == position-1) {
            newNode->next = targetNode->next;
            targetNode->next = newNode;
            break;
        }
        targetNode = targetNode->next;
        counter++;
    }
}

LinkedList::~LinkedList() {
    if(head!=NULL)
        delete head;
}