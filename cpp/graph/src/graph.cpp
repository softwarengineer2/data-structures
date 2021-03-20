#include "../include/graph.hpp"

void Graph::Traverse() {
    Node *tempNode;
    for (int i = 0; i < totalVertices; i++) {
        tempNode = adjList[i];
        while(tempNode != nullptr) {
            std::cout<<i<<"-"<<tempNode->data<<" w:"<<tempNode->weight<<" ";
            tempNode = tempNode->next;
        }
        std::cout<<std::endl;
    }
}
Graph::Graph(Edge** edgeList, int totalEdges, int totalVertices) {
    this->totalVertices = totalVertices;
    adjList = new Node*[totalVertices]();
    
    for(int i=0;i < totalEdges; i++) {
        Node *tempNode = new Node(); 
        tempNode->data = edgeList[i]->end;
        tempNode->weight = edgeList[i]->weight;
        tempNode->next = this->adjList[edgeList[i]->start];
        this->adjList[edgeList[i]->start] = tempNode;
        delete edgeList[i];
    }
}
Graph::~Graph() {
    Node *tempNode, *deleteNode;
    for (int i = 0; i < totalVertices; i++) {
        tempNode = adjList[i];
        while(tempNode != nullptr) {
            deleteNode = tempNode;
            tempNode = tempNode->next;
            delete deleteNode;
            deleteNode = nullptr;
        }
    }
    delete[] adjList;
}
void Graph::BFS(int s) {
    bool* visited = new bool[totalVertices]();
    std::queue<int> queue;
    visited[s] = true;
    queue.push(s);
    
    Node *tempNode;
    while(!queue.empty()) 
    { 
        s = queue.front();
        std::cout << s << " "; 
        queue.pop();
        tempNode = adjList[s];
        while(tempNode != nullptr) {
            if (!visited[tempNode->data]) 
            { 
                visited[tempNode->data] = true; 
                queue.push(tempNode->data); 
            } 
            tempNode = tempNode->next;
        }
    }
    delete[] visited;
}
void Graph::DFSUtil(int s, bool* visited) {
    Node* tempNode = adjList[s];
    while(tempNode != nullptr) {
        if (!visited[tempNode->data]) 
        { 
            std::cout<<tempNode->data<<" ";
            visited[tempNode->data] = true;
            DFSUtil(tempNode->data, visited);
        } 
        tempNode = tempNode->next;
    }
}
void Graph::DFS(int s) {
    bool* visited = new bool[totalVertices]();
    std::cout<<s<<" ";
    if(!visited[s]) {
        visited[s] = true;
        DFSUtil(s, visited);
    }
    delete[] visited;
}