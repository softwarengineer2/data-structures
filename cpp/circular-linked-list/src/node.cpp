#include <iostream>
#include "../include/node.hpp"

Node::Node(int data) {
    this->data = data;
}

Node::~Node() {
    //if(next!=NULL)
    //    delete next;
}