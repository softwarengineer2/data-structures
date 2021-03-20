#include <iostream>
#include "../include/edge.hpp"
#include "../include/graph.hpp"

using namespace std;

int main() {
    const int N = 8;
    const int n = 6;
    Edge** edges = new Edge*[n]{
        new Edge{0,4,1},
        new Edge{4,6,1},
        new Edge{0,7,1},
        new Edge{0,1,1},
        new Edge{1,5,1},
        new Edge{1,3,1}
    };

    Graph* graph = new Graph(edges, n, N);
    graph->Traverse();
    graph->BFS(0);
    cout<<endl;
    graph->DFS(0);
    cout<<endl;
    delete[] edges;
    delete graph;
    return 0;
}