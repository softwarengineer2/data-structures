#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include "../include/linked_list.hpp"
#include "../include/edge.hpp"

using namespace std;


class Graph{
    Node** adjList;
    int totalVertices;

public:
    void Traverse() {
        Node *tempNode;
        for (int i = 0; i < totalVertices; i++) {
            tempNode = adjList[i];
            while(tempNode != nullptr) {
                cout<<i<<"-"<<tempNode->data<<" w:"<<tempNode->weight<<" ";
                tempNode = tempNode->next;
            }
            cout<<endl;
        }
    }

    Graph(Edge** edgeList, int totalEdges, int totalVertices) {
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

    ~Graph() {
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

    void BFS(int s) {
        bool* visited = new bool[totalVertices]();
        queue<int> queue;

        //cout<<"Visited[0]"<<visited[0]<<endl;

        //for(int i = 0; i < totalVertices; i++) 
        //    visited[i] = false; 

        visited[s] = true;
        queue.push(s);

        //cout<<"BFS [0]="<<adjList[s]->data<<endl;
        
        Node *tempNode;
        while(!queue.empty()) 
        { 
            s = queue.front();
            cout << s << " "; 
            queue.pop();
            tempNode = adjList[s];
            while(tempNode != nullptr) {
                //cout<<"adjList["<<s<<"] == "<<tempNode->data<<endl;
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

    void DFSUtil(int s, bool* visited) {
        Node* tempNode = adjList[s];
        while(tempNode != nullptr) {
            if (!visited[tempNode->data]) 
            { 
                cout<<tempNode->data<<" ";
                visited[tempNode->data] = true;
                DFSUtil(tempNode->data, visited);
            } 
            tempNode = tempNode->next;
        }
    }

    void DFS(int s) {
        bool* visited = new bool[totalVertices]();
        cout<<s<<" ";
        if(!visited[s]) {
            visited[s] = true;
            DFSUtil(s, visited);
        }
        delete[] visited;
    }
};

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