#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* findMiddle(Node *head){
    Node *slow=head;
    Node *fast=head;
    while (fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;}


Node* reverselist(Node *head){
    Node *curr=head;
    Node*prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}


bool isMirrorSequence(Node *head) {
Node* mid=findMiddle(head);
Node* Halfhead=reverselist(mid);

Node *p1=head;
Node *p2=Halfhead;

while(p2!=NULL){
    if(p2->data!=p1->data){
        return false;
    }
    p1=p1->next;
    p2=p2->next;

}
return true;

}