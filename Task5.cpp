#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int findlength(Node* head){
    Node*curr=head;
    int length=0;
    while(curr!=NULL){
        length++;
        curr=curr->next;
    }
    return length;
}

Node* findIntersection(Node*h1,Node* h2){
    int l1=findlength(h1);
    int l2=findlength(h2);
    Node*curr1=h1;
    Node*curr2=h2;
    if(l1>l2){
        for(int i=1;i<=(l1-l2);i++){
            curr1=curr1->next;
        }

    }
    else if(l2>l1){
        for(int i=1;i<=(l2-l1);i++){
            curr2=curr2->next;
        }
    }
    while(curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return curr1;
}