#include <iostream>
#include "../include/queue.hpp"

void Stack::Enqueue(int data) {
    std::cout<<"Stack::InsertAtfront"<<std::endl;
    Node* newNode = new Node(data);
    if(front != nullptr) {
        std::cout<<"front != nullptr"<<std::endl;
        rear->next = newNode;
    }
    else {
        std::cout<<"front == nullptr"<<std::endl;
        front = newNode;
    }
    rear = newNode;
    size++;
}

int Stack::Dequeue() {
    std::cout<<"Stack::Pop"<<std::endl;
    int retValue = -1;
    if(front == nullptr) {
        throw std::overflow_error("Stack Underflow!");
    }
    else {
        retValue = front->data;
        Node* tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    size--;
    if(size == 0)
        rear = nullptr;
    return retValue;
}

int Stack::Front() {
    std::cout<<"Front : "<<front<<std::endl;
    return (front!=nullptr)?front->data:-1;
}


int Stack::Rear() {
    std::cout<<"Rear : "<<rear<<std::endl;
    return (rear!=nullptr)?rear->data:-1;
}

bool Stack::IsEmpty() {
    return (size==0)?true:false;
}

Stack::~Stack() {
    Node* tempPtr = nullptr;
    Node* nextPtr = front;
    while(nextPtr!=nullptr)
    {
        tempPtr = nextPtr;
        nextPtr = nextPtr->next;
        delete tempPtr;
    }
}