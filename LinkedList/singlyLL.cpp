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
void insertHead(Node* &head,int data){
    Node *temp=  new Node (data);
    temp->next=head;
    head=temp;

}
void insertTail(Node* &tail,int data){
    Node* temp= new Node(data);
    tail->next= temp;
    tail =temp;

}
void insertion(int data,int position,Node* &head,Node* &tail){
    //insertion at first position
    if(position==1){
        insertHead(head,data);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count ++;
    }
    //insertion at last position
    if(temp->next==NULL){
        insertTail(tail,data);
        return ;
    }
    Node *n1=new Node(data);
    n1->next=temp->next;
    temp->next=n1;


}
void deletion(int position,Node* &head,Node* &tail){
    // deletion of head node
    if (position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deletion of other node
        int count =1;
        Node* curr=head;
        Node* prev=NULL;
        while(count<position){
            prev=curr;
            curr =curr->next;
            count++;
        }
        //pointing the tail to previos if its last element
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

Node* reverse(Node* &head){
    Node* next=NULL;
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
Node* reverse1(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
Node* reversek(Node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    Node* curr=head;
    Node* forward=NULL;
    Node* prev=NULL;
    int count=0;
    while(count<k &&curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    
    if(forward!=NULL){
        head->next=reversek(forward,k);
    }
    return prev;
}
    Node* removeNthFromEnd(Node* head, int n) {
        Node* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL) {
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        Node* slow=head;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        Node* temp=slow->next;
        slow->next=slow->next->next;
        temp->next=NULL;
        delete temp;
         

        
        return head;
    }
Node* kthNode(Node* head,int k){
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==k) return temp;

        count++;
        temp=temp->next;
    }
    //cout<<temp->data<<endl;
    return temp;
}
Node* rotateList(Node* head,int k){
    if(head==NULL || k==0)
        return head;
    Node* tail=head;
    int count=1;
    while(tail->next!=NULL){
        tail=tail->next;
        count++;
    }
    //cout<<count<<" "<<tail->data<<endl;
    if(k%count==0) return head;
    k=k%count;
    Node* temp=kthNode(head,count-k);
    tail->next=head;
    head=temp->next;
    temp->next=NULL;
    return head;

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
    Node *node1=new Node(1);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    insertTail(tail,2);
    insertTail(tail,3);
    //insertTail(tail,4);
    //insertTail(tail,5);
    print(head);
    /*insertTail(tail,19);
    print(head);
    insertion(8,1,head,tail);
    print(head);
    insertion(22,5,head,tail);
    print(head);
    insertion (17,3,head,tail);
    print(head);
    head=reversek(head,3);*/
    cout<<" cycle : "<< hasCycle(head)<<endl;
    head=removeNthFromEnd(head,5);
    //head=rotateList(head,20000);
    print(head);
}
