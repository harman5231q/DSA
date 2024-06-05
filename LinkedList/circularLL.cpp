#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        // if node is pointing to some value
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"destructor called  for : "<<value<<endl;
    }

};
void insertion(Node* &tail,int value,int data){
    if(tail==NULL){
        Node *temp=new Node(data);
        temp->next=temp;
        tail=temp;
    }
    else{
        // assuming that element exists in linked list
        Node *curr=tail;
        while(curr->data!=value){
            curr=curr->next;
        }
        Node *temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"No element in linked list"<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=temp);
    cout<<endl;
}
void deletion(Node* &tail,int value){
    if(tail==NULL){
        cout<<"No element in linked list"<<endl;
        
    }
    else{
        //assuming that element is present
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //if current is pointing to tail
        if(tail==curr){
            tail=prev;
        }
        // if only one element is present
        if(curr==prev){
            tail=NULL;
        }
        curr->next=NULL;
        delete curr;
    }
}
    bool hasCycle(Node* head){
        if(head==NULL){
            return false;
        }

        Node* fast=head;
        Node* slow= head;
        while(fast!=NULL && slow !=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;

            if(slow==fast){
                return true;
            }
        }

        return false;
    }
int main(){
    Node* tail=NULL;
    /*insertion(tail,3,3);
    insertion(tail,3,5);
    insertion(tail,5,6);
    insertion(tail,3,4);
    insertion(tail,6,7);
    print(tail);*/
    cout<<" cycle : "<< hasCycle(tail)<<endl;
   /*  cout<<"tail : "<<tail->data<<endl;
    
    deletion(tail,7);
     cout<<"tail : "<<tail->data<<endl;
    print(tail);
    deletion(tail,6);
     cout<<"tail : "<<tail->data<<endl;
    print(tail);
    deletion(tail,5);
     cout<<"tail : "<<tail->data<<endl;
    print(tail);
    deletion(tail,4);
     cout<<"tail : "<<tail->data<<endl;
    print(tail);
    deletion(tail,3);
    cout<<"tail : "<<tail->data<<endl;
    print(tail);
    */
}