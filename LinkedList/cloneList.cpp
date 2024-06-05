#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    void insertTail(Node* &head,Node* &tail,int data){
        Node* temp= new Node(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        
    }
public:
    Node* copyRandomList(Node* head) {
        //step 1: clone list
        Node* clonehead=NULL;
        Node* clonetail=NULL;

        Node* temp=head;
        while(temp!=NULL){
            insertTail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        //step 2: point to clone list
        Node* originalptr=head;
        Node* cloneptr=clonehead;
        while(originalptr!=NULL&& cloneptr!=NULL){
            Node* next=originalptr->next;

            originalptr->next=cloneptr;
            originalptr=next;

            next=cloneptr->next;
            cloneptr->next=originalptr;
            cloneptr=next;
        }
        // step 3: copy random pointers
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random= temp->random ? temp->random->next : temp->random;
            }
            temp=temp->next->next;
            
        }
        // step 4: revert step 2
        originalptr=head;
        cloneptr=clonehead;
        while(originalptr!=NULL&& cloneptr!=NULL){
            originalptr->next=cloneptr->next;
            originalptr=originalptr->next;
            if(originalptr!=NULL){
                cloneptr->next=originalptr->next;
            }
            cloneptr=cloneptr->next;
        }
        return clonehead;
        


        
    }
};