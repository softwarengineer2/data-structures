#include <iostream>
#include "../include/node.hpp"

Node::Node(int data, int weight/*=1*/) {
    this->data = data;
    this->weight = weight;
}

//Node::~Node() {
    //if(next!=nullptr)
    //    delete next;
//}