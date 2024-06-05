#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Destructor called for : "<<value<<endl;
    }

    
};
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
void insertHead(Node* &head,Node* &tail ,int data){
    if(head==NULL){
        Node *temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node *temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void insertTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node *temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(data);
    tail->next= temp;
    temp->prev=tail;
    tail = temp;
    }
}
void insertion(Node* &head,Node* &tail,int data,int position ){
    //insertion at first position
    if(position==1){
        insertHead(head,tail,data);
        return;
    }
    Node* temp=head;
    int count =1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    // insertion at last position
    if(temp->next==NULL){
        insertTail(head,tail,data);
        return ;
    }
    // insertion between head and tail
    Node *insertnode=new Node(data);
    temp->next->prev=insertnode;
    insertnode->next=temp->next;
    insertnode->prev=temp;
    temp->next=insertnode;

}
void deletion(Node* &head,Node* &tail,int position){
    // deletion  for head
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr =head;
        Node* pre=NULL;
        int count =1;
        while(count<position){
            pre=curr;
            curr=curr->next;
            count ++;
        }
        // deletion for tail
        if(curr->next==NULL){
            curr->prev=NULL;
            pre->next=NULL;
            tail=pre;
            delete curr;
        }
        // deletion between head and tail   
        else{
            curr->next->prev=pre;
            pre->next=curr->next;
            curr->next= NULL;
            curr->prev=NULL;
            delete curr;
        }

    }
}
int main(){
    Node *temp=new Node(18);
    Node* head=temp;
    Node* tail=temp;
    insertHead(head,tail,15);
    print(head);
    insertTail(head,tail,19);
    print(head);
    insertion(head,tail,12,1);
    print(head);
    insertion(head,tail,13,5);
    print(head);
    insertion(head,tail,16,4);
    print(head);
    deletion(head,tail,5);
    print(head);
    cout<<" head :"<<head->data<<endl;
    cout<<" tail :"<<tail->data<<endl;    

    return 0;
}

