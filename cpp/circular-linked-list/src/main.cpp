#include <iostream>
#include "../include/circular_linked_list.hpp"

using namespace std;

int main() {
    CircularLinkedList* x1 = new CircularLinkedList();
    x1->InsertAtBeginning(3);
    x1->InsertAtLast(4);
    x1->InsertAtLast(5);
    x1->InsertAtBeginning(1);
    x1->InsertAtPosition(2,4);
    x1->InsertAtLast(6);
    x1->InsertAtLast(7);
    x1->DeleteAtPosition(2);
    x1->Traverse();
    delete x1;

    return 0;
}