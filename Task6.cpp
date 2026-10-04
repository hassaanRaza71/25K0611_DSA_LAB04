#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* evenNodes(Node *head){
    Node* curr=head;
    Node* even=NULL;
    while(curr->!=NULL){
        if(curr->data%==0){
            if(even==NULL){
                even=curr;
            }
            else{
                even->next=curr;
            }
        }
        
    }
    return even;
}
Node* oddNodes(Node *head){
    Node* curr=head;
    Node* odd=NULL;
    while(curr->!=NULL){
        if(curr->data%==1){
            if(odd==NULL){
                odd=curr;
            }
            else{
                odd->next=curr;
            }
        }
        
    }
    return odd;
}
Node*sort(Node *head){
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

Node* rearrange(Node* head){
    Node *odd=sort(oddNodes(head));
    Node *even=sort(evenNodes(even));
    Node *curr=odd;
    while(curr->next!=NULL){
        currr=curr->next;
    }
    curr->next=even;
    return odd;
}