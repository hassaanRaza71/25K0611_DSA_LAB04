#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *next;
};


Node*  removeloop(Node *head){
    Node* slow=head;
    Node* fast=head->next
    bool loopexist=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loopexist=true;
            break;
        }
    }
    if(loopexist){
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else{
            while(slow->next!=fast->next){
                slow=slow->next;
                fast=fast->next;

            }
            fast->next=NULL;
        }

    }
    return head;
}