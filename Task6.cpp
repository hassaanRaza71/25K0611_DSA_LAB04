#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* evenNodes(Node *head) {
    Node* curr = head;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    
    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            Node* newNode = new Node{curr->data, NULL};
            if (evenHead == NULL) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        curr = curr->next;
    }
    return evenHead;
}

Node* oddNodes(Node *head) {
    Node* curr = head;
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    
    while (curr != NULL) {
        if (curr->data % 2 != 0) {
            Node* newNode = new Node{curr->data, NULL};
            if (oddHead == NULL) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        }
        curr = curr->next;
    }
    return oddHead;
}

Node* sort(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    bool swapped;
    Node* curr;

    do {
        swapped = false;
        curr = head;

        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);

    return head;
}

Node* rearrange(Node* head) {
    if (head == NULL) return NULL;

    Node* odd = sort(oddNodes(head));
    Node* even = sort(evenNodes(head));
    
    if (odd == NULL) return even;
    
    Node* curr = odd;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = even;
    
    return odd;
}
