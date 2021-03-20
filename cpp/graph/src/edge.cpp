#include <iostream>
#include "../include/edge.hpp"

Edge::Edge(int start, int end, int weight/*=1*/) {
    this->start = start;
    this->end = end;
    this->weight = weight;
}