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

int tripletscheck(Node *head, int target) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return 0;
    }

    int count = 0;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    for (Node* i = head; i->next->next != NULL; i = i->next) {
        Node* left = i->next;
        Node* right = tail;

        while (left != NULL && right != NULL && left != right && right->next != left) {
            int sum = i->data + left->data + right->data;

            if (sum == target) {
                count++;
                left = left->next;
                right = right->prev;
            } 
            else if (sum > target) {
                right = right->prev;
            } 
            else {
                left = left->next;
            }
        }
    }
    return count;
}
