#include <iostream>
#include "../include/stack.hpp"

void Stack::Push(int data) {
    std::cout<<"Stack::InsertAttop"<<std::endl;
    Node* newNode = new Node(data);
    if(top != nullptr)
        newNode->next = top;
    top = newNode;
    size++;
}

int Stack::Pop() {
    std::cout<<"Stack::Pop"<<std::endl;
    int retValue = -1;
    if(top == nullptr) {
        throw std::overflow_error("Stack Underflow!");
    }
    else {
        retValue = top->data;
        Node* tempPtr = top;
        top = top->next;
        delete tempPtr;
    }
    size--;
    return retValue;
}

int Stack::Top() {
    std::cout<<"Stack::Top"<<std::endl;
    int retValue = -1;
    if(top == nullptr) {
        throw std::overflow_error("Stack Underflow!");
    }
    else {
        retValue = top->data;
    }
    return retValue;
}

bool Stack::IsEmpty() {
    return (size==0)?true:false;
}

Stack::~Stack() {
    Node* tempPtr = nullptr;
    Node* nextPtr = top;
    while(nextPtr!=nullptr)
    {
        tempPtr = nextPtr;
        nextPtr = nextPtr->next;
        delete tempPtr;
    }
}