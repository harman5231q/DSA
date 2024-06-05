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
        cout<<"Destructor called  for : "<<value<<endl;
    }

};

class Stack{
    Node* head;
    public:
    Stack(){
        head=NULL;
    }

    void push(int val){
        Node* temp= new Node(val);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
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
        if(head!=NULL){
            return head->data;
            
        }
        cout<<"Stack is empty"<<endl;
        return -1;

    }
    bool empty(){
        if(head==NULL){
            return true;
        }
        return false;

    }
};

int main(){
   /* Stack st;
    st.pop();
    st.push(4);
    cout<<"Top : "<<st.top()<<endl;
    st.push(6);
    cout<<"Top : "<<st.top()<<endl;
    st.push(7);
    cout<<"Top : "<<st.top()<<endl; 
    st.push(8);
    cout<<"Top : "<<st.top()<<endl; 
    st.push(9);
    cout<<"Top : "<<st.top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    if(st.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }
    */
   Stack obj;
    obj.push(-2);
    obj.push(0);
    obj.push(-3);
    cout<<" min : "<<obj.top()<<endl;
    obj.pop();
    cout<<" top : "<<obj.top()<<endl;
    cout<<" min : "<<obj.top()<<endl;




}