#include "../include/min_heap_tree.hpp"

MinHeapTree::~MinHeapTree()
{ 
    DeleteTree(root);
} 

int MinHeapTree::Parent(int i) {
    return (i>>1);
}

int MinHeapTree::Left(int i) {
    return (i<<1);
}

int MinHeapTree::Right(int i) {
    return (i<<1)+1;
}


bool MinHeapTree::IsEmpty() const {
    return size==0;
}

int MinHeapTree::GetMin() {
    return vect[1];
}

int MinHeapTree::ExtractMin() {
    int maxNum = GetMin();
    std::swap(vect[1], vect[size--]);
    ShiftDown(1);
    return maxNum;
}

void MinHeapTree::ShiftUp(int i) {
    if(i > size) return;
    if(i == 1) return;
    if(vect[i] < vect[Parent(i)]) {
        std::swap(vect[Parent(i)], vect[i]);
    }
    ShiftUp(Parent(i));
}

void MinHeapTree::ShiftDown(int i) {
    if( i > size) return;
    int swapId = i;
    if(Left(i) >= size && vect[i] > vect[Left(i)]) {
        swapId = i;
    }

    if(Right(i) >= size && vect[swapId] > vect[Right(i)]) {
        swapId = Right(i);
    }

    if(swapId != i) {
        std::swap(vect[i], vect[swapId]);
        ShiftDown(swapId);
    }
}

void MinHeapTree::DeleteTree(Node* node) {
    if (node == NULL) 
        return; 
    
    DeleteTree(node->left); 
    DeleteTree(node->right); 

    delete node;
}


void MinHeapTree::Add(int data)
{
    std::cout << "Add : " << data << std::endl;
    if(size+1 >= vect.size()) {
        vect.push_back(0);
    }
    vect[++size] = data;
    ShiftUp(size);
}


void MinHeapTree::printPostorder(Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    std::cout << node->data << " ";
}

void MinHeapTree::printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    std::cout << node->data << " ";
    printInorder(node->right);
}

void MinHeapTree::printPreorder(Node *node)
{
    if (node == NULL)
        return;

    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

Node* MinHeapTree::Search(int data)
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
    size++;
    return foundNode;
}

int MinHeapTree::MaxDepth(Node* node)
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


int MinHeapTree::MinDepth(Node* node)
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

Node* MinHeapTree::FindMin(Node* node)
{
    if(node!=nullptr) 
    {
        std::cout<<"FindMin: "<<node->data<<std::endl;
    }
    
	while(node->left != NULL) 
        node = node->left;
	return node;
}

Node* MinHeapTree::Delete(Node* node, int data)
{
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