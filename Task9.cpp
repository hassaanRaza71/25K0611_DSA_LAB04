#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int id;
    int severity;
    Node *next;
    Node *prev;
};

int getLength(Node* head) {
    int length = 0;
    Node* curr = head;
    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

Node* getNodeAt(Node* head, int index) {
    Node* curr = head;
    for (int i = 0; i < index && curr != NULL; i++) {
        curr = curr->next;
    }
    return curr;
}

Node* shellSortPatients(Node* head) {
    int size = getLength(head);
    if (size <= 1) {
        return head;
    }

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int j = i;
            while (j >= gap) {
                Node* nodeJ = getNodeAt(head, j);
                Node* nodeGap = getNodeAt(head, j - gap);

                if (nodeGap->severity > nodeJ->severity) {
                    swap(nodeGap->id, nodeJ->id);
                    swap(nodeGap->severity, nodeJ->severity);
                    j -= gap;
                } else {
                    break;
                }
            }
        }
    }
    return head;
}
