#include <iostream>
#include "../include/max_heap_tree.hpp"
#include "../include/min_heap_tree.hpp"

using namespace std;

int main() {
    MaxHeapTree* maxHeapTree = new MaxHeapTree();

    if(maxHeapTree->IsEmpty()) {
        cout<<"Yes, it is empty"<<endl;
    }
    else {
        cout<<"No, it is not empty"<<endl;
    }
    maxHeapTree->Add(15);
    maxHeapTree->Add(10);
    maxHeapTree->Add(8);
    maxHeapTree->Add(12);
    maxHeapTree->Add(20);
    maxHeapTree->Add(16);
    maxHeapTree->Add(25);
    maxHeapTree->Add(4);
    maxHeapTree->Add(9);
    maxHeapTree->Add(11);
    cout<<"Max: "<<maxHeapTree->ExtractMax()<<endl;
    
    if(maxHeapTree->IsEmpty()) {
        cout<<"Yes, it is empty"<<endl;
    }
    else {
        cout<<"No, it is not empty"<<endl;
    }

    MinHeapTree* minHeapTree = new MinHeapTree();

    if(minHeapTree->IsEmpty()) {
        cout<<"Yes, it is empty"<<endl;
    }
    else {
        cout<<"No, it is not empty"<<endl;
    }
    minHeapTree->Add(15);
    minHeapTree->Add(10);
    minHeapTree->Add(8);
    minHeapTree->Add(12);
    minHeapTree->Add(20);
    minHeapTree->Add(16);
    minHeapTree->Add(25);
    minHeapTree->Add(4);
    minHeapTree->Add(9);
    minHeapTree->Add(11);
    cout<<"Min: "<<minHeapTree->ExtractMin()<<endl;
    
    if(minHeapTree->IsEmpty()) {
        cout<<"Yes, it is empty"<<endl;
    }
    else {
        cout<<"No, it is not empty"<<endl;
    }

    /*maxHeapTree->printPreorder(maxHeapTree->root);
    cout<<endl;
    maxHeapTree->printPostorder(maxHeapTree->root);
    cout<<endl;

    Node* test = maxHeapTree->Search(10);
    if(test!=nullptr) {
        cout<<"Found It"<<endl;
    }

    maxHeapTree->Delete(maxHeapTree->root, 10);
    
    maxHeapTree->printInorder(maxHeapTree->root);
    cout<<endl;
    maxHeapTree->printPreorder(maxHeapTree->root);
    cout<<endl;
    maxHeapTree->printPostorder(maxHeapTree->root);
    cout<<endl;*/
    
    delete maxHeapTree;
    delete minHeapTree;
    return 0;
}