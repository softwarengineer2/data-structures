#include <iostream>
#include "../include/stack.hpp"

using namespace std;

int main() {
    Stack* x1 = new Stack();
    x1->Push(4);
    x1->Push(5);
    x1->Push(2);
    int popValue = x1->Pop();
    cout<<popValue<<endl;
    int topValue = x1->Top();
    cout<<topValue<<endl;
    topValue = x1->Pop();
    cout<<topValue<<endl;
    topValue = x1->Pop();
    cout<<topValue<<endl;
    bool isEmpty = x1->IsEmpty();
    cout<<isEmpty<<endl;
    delete x1;

    return 0;
}