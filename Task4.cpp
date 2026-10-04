#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* mergeSortedLists(Node* h1, Node* h2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }

    if (h1 != NULL) {
        tail->next = h1;
    } else {
        tail->next = h2;
    }

    return dummy.next;
}
