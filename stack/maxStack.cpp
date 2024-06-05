#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    int maxi;
    Node* next;

    Node(int val){
        this->next=NULL;
        this->data=val;
        this->maxi=INT_MIN;
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

class MaxStack{
    Node* head= NULL;

    public:
    MaxStack(){
        
    }
    void push(int val){
        Node* temp=new Node(val);
        if(head==NULL){
            temp->maxi=val;
            head=temp;
        }
        else{
            if(head->maxi<val){
                temp->maxi=max(val,head->maxi);
                temp->next=head;
                head=temp;
  
            }
            else{
                temp->next=head;
                temp->maxi=head->maxi;
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
        if(head==NULL){
            return -1;
        }
        return head->data;

    }
    int getMax(){
        if(head==NULL){
            return -1;
        }
        return head->maxi;

    }
    void print(){
        Node* temp=head;
        while (temp!=NULL)
        {
            cout<<'['<<temp->data<<']'<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
};

int main(){
    MaxStack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<"printing"<<endl;
    obj.print();
    cout<<" Max : "<<obj.getMax()<<endl;
    obj.pop();
    cout<<" top : "<<obj.top()<<endl;
    cout<<" Max : "<<obj.getMax()<<endl;




    
}