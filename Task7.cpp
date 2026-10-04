#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;

    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* duplicate = curr->next;
            
            curr->next = duplicate->next;
            if (duplicate->next != NULL) {
                duplicate->next->prev = curr;
            }
            
            delete duplicate;
        } else {
            curr = curr->next;
        }
    }
    
    return head;
}
