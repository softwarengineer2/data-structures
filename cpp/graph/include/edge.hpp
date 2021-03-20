
#ifndef EDGE_H_
#define EDGE_H_

class Edge {

public:
    int start, end, weight;

    Edge()=default;
    Edge(int start, int end, int weight=1);
};
#endif