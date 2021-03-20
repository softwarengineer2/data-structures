
#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <queue>
#include "node.hpp"
#include "edge.hpp"

class Graph {

public:
    Node** adjList;
    int totalVertices;

    Graph()=default;
    Graph(Edge** edgeList, int totalEdges, int totalVertices);
    ~Graph();

    void Traverse();
    void BFS(int s);
    void DFS(int s);
    void DFSUtil(int s, bool* visited);
};
#endif