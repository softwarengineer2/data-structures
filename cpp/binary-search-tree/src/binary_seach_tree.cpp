#include "../include/binary_seach_tree.hpp"

BinarySearchTree::~BinarySearchTree()
{ 
    DeleteTree(root);
} 

void BinarySearchTree::DeleteTree(Node* node) {
    if (node == NULL) 
        return; 
  
    
    DeleteTree(node->left); 
    DeleteTree(node->right); 

    delete node;
}

void BinarySearchTree::printPostorder(Node *node)
{
    //std::cout<<"BinarySearchTree::printPostorder  "<<std::endl;
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

void BinarySearchTree::printInorder(Node *node)
{
    //std::cout<<"BinarySearchTree::printInorder  "<<std::endl;
    if (node == NULL)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void BinarySearchTree::printPreorder(Node *node)
{
    //std::cout<<"BinarySearchTree::printPreorder  "<<std::endl;
    if (node == NULL)
        return;

    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void BinarySearchTree::Add(int data)
{
    std::cout << "Add : " << data << std::endl;
    if (totalNodes == 0)
    {
        root = new Node(data);
        //std::cout<<"Root:"<<std::endl;
    }
    else
    {
        //left.value < data < right.value
        Node *tempNode = root;
        while (tempNode != nullptr)
        {
            if (data >= tempNode->data)
            {
                if (tempNode->right == nullptr)
                {
                    //std::cout<<"right new "<<std::endl;
                    tempNode->right = new Node(data);
                    break;
                }
                else
                {
                    //std::cout<<"right old "<<std::endl;
                    tempNode = tempNode->right;
                }
            }
            else
            { //if(data <= tempNode->data) {
                if (tempNode->left == nullptr)
                {
                    //std::cout<<"left new "<<std::endl;
                    tempNode->left = new Node(data);
                    break;
                }
                else
                {
                    //std::cout<<"left old "<<std::endl;
                    tempNode = tempNode->left;
                }
            }
        }
    }
    totalNodes++;
}

Node* BinarySearchTree::Search(int data)
{
    std::cout << "Search : " << data << std::endl;
    Node* foundNode = nullptr;
    Node *tempNode = root;
    while (tempNode != nullptr)
    {
        if(data == tempNode->data) 
        {
            foundNode = tempNode;
            break;
        }
        if (data >= tempNode->data)
        {
            if (tempNode->right == nullptr)
            {
                break;
            }
            else
            {
                tempNode = tempNode->right;
            }
        }
        else
        { 
            if (tempNode->left == nullptr)
            {
                break;
            }
            else
            {
                tempNode = tempNode->left;
            }
        }
    }
    totalNodes++;
    return foundNode;
}

int BinarySearchTree::MaxDepth(Node* node)
{
    if (node==NULL)
        return 0;
   else
   {
       int rDepth = MaxDepth(node->right);
       int lDepth = MaxDepth(node->left);

       if (lDepth > rDepth)
       {
           return(lDepth+1);
       }
       else
       {
            return(rDepth+1);
       }
   }
}  


int BinarySearchTree::MinDepth(Node* node)
{
    if (node==NULL)
        return 0;
   else
   {
       int rDepth = MinDepth(node->right);
       int lDepth = MinDepth(node->left);

       if (lDepth > rDepth)
       {
           return(lDepth-1);
       }
       else
       {
            return(rDepth-1);
       }
   }
}  

Node* BinarySearchTree::FindMin(Node* node)
{
    if(node!=nullptr) 
    {
        std::cout<<"FindMin: "<<node->data<<std::endl;
    }
    
	while(node->left != NULL) 
        node = node->left;
	return node;
}

Node* BinarySearchTree::Delete(Node* node, int data)
{
    //std::cout << "Delete : " << data << std::endl;
    if(node == nullptr) {
        return node; 
    }
	else if(data < node->data) {
        node->left = Delete(node->left,data);

    }
	else if (data > node->data) {
        node->right = Delete(node->right,data);
    }
    else {
		if(node->left == NULL && node->right == NULL) { 
			delete node;
			node = NULL;
		}
		else if(node->left == NULL) {
			Node *temp = node;
			node = node->right;
			delete temp;
		}
		else if(node->right == NULL) {
			Node *temp = node;
			node = node->left;
			delete temp;
		}
		else { 
			Node *temp = FindMin(node->right);
			node->data = temp->data;
			node->right = Delete(node->right,temp->data);
		}
	}
    return node;
}