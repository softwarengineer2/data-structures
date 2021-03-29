#include "../include/binary_seach_tree.hpp"

BinarySearchTree::~BinarySearchTree() {
    /*Node *tempNode, *deleteNode;
    for (int i = 0; i < totalVertices; i++) {
        tempNode = adjList[i];
        while(tempNode != nullptr) {
            deleteNode = tempNode;
            tempNode = tempNode->next;
            delete deleteNode;
            deleteNode = nullptr;
        }
    }
    delete[] adjList;*/
}


void BinarySearchTree::printPostorder(Node* node)
{
    //std::cout<<"BinarySearchTree::printPostorder  "<<std::endl;
    if (node == NULL)
        return;
 
    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";

}
 
void BinarySearchTree::printInorder(Node* node)
{
    //std::cout<<"BinarySearchTree::printInorder  "<<std::endl;
    if (node == NULL)
        return;
 
    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);

}
 
void BinarySearchTree::printPreorder(Node* node)
{
    //std::cout<<"BinarySearchTree::printPreorder  "<<std::endl;
    if (node == NULL)
        return;
 
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);

}

void BinarySearchTree::Add(int data) {
    std::cout<<"Add : "<<data<<std::endl;
    if(totalNodes == 0) {
         root = new Node(data);
         //std::cout<<"Root:"<<std::endl;
    }
    else {
        //left.value < data < right.value
        Node* tempNode = root;
        while(tempNode != nullptr) {
           if(data >= tempNode->data) {
               if(tempNode->right == nullptr) {
                   //std::cout<<"right new "<<std::endl;
                   tempNode->right = new Node(data);
                   break;
               }
               else {
                   //std::cout<<"right old "<<std::endl;
                   tempNode = tempNode->right;
               }
           }
           else {//if(data <= tempNode->data) {
               if(tempNode->left == nullptr) {
                   //std::cout<<"left new "<<std::endl;
                   tempNode->left = new Node(data);
                   break;
               }
               else {
                   //std::cout<<"left old "<<std::endl;
                   tempNode = tempNode->left;
               }
           }
        }
    }
    totalNodes++;
    //std::cout<<data<<std::endl;
}