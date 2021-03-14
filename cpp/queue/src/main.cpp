#include <iostream>
#include "../include/queue.hpp"

using namespace std;

int main() {
    Stack* x1 = new Stack();
    x1->Enqueue(1);
    x1->Enqueue(2);
    x1->Enqueue(3);
    x1->Enqueue(4);
    x1->Enqueue(5);
    int popValue = x1->Dequeue();
    cout<<popValue<<endl;
    popValue = x1->Dequeue();
    cout<<popValue<<endl;
    popValue = x1->Dequeue();
    cout<<popValue<<endl;
    popValue = x1->Rear();
    cout<<popValue<<endl;
    popValue = x1->Front();
    cout<<popValue<<endl;
    bool isEmpty = x1->IsEmpty();
    cout<<isEmpty<<endl;
    delete x1;

    return 0;
}