#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    int mini;
    Node* next;

    Node(int val){
        this->next=NULL;
        this->data=val;
        this->mini=INT_MAX;
    }

    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Destructor called For : "<<val<<endl;
    }
    
};

class MinStack{
    Node* head= NULL;

    public:
    MinStack(){
        
    }
    void push(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            temp->mini=val;
            head=temp;
        }
        else{
            if(head->mini>val){
                temp->mini=min(val,head->mini);
                temp->next=head;
                head=temp;
  
            }
            else{
                temp->next=head;
                temp->mini=head->mini;
                head=temp;

            }
        }

    }
    void pop(){
        if(head==NULL){
            cout<<"Stack underflow"<<endl;
            return ;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }
    int top(){
        return head->data;

    }
    int getMin(){
        return head->mini;

    }
    void print(){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
};

int main(){
    MinStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<"printing"<<endl;
    obj.print();
    cout<<" min : "<<obj.getMin()<<endl;
    obj.pop();
    cout<<" top : "<<obj.top()<<endl;
    cout<<" min : "<<obj.getMin()<<endl;




    
}