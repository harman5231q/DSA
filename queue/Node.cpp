#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;


    Node(int val){
        this->data=val;
        this->next=NULL;
    }

    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }

        cout<<"Destructor called for Node : "<<val<<endl;
    }

};