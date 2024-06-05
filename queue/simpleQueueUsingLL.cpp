#include<iostream>
#include"Node.cpp"
using namespace std;

class QueueLL{
    Node* head;
    Node* tail;

    public:

    QueueLL(){
        head=NULL;
        tail=NULL;
    }

    void push(int val){
        Node* temp= new Node(val);

        if(head==NULL ){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }

    }

    void pop(){
        if(head==NULL){
            cout<< "Queue Underflow"<<endl;
        }
        else{
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }

    }

    int front(){
        if(head==NULL){
            cout<<"No element present "<<endl;
            return -1;
        }
        return head->data;
    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }

        return false;

    }

    

};

int main(){
    QueueLL qt;


    qt.push(12);
    qt.push(13);
    qt.push(14);
    qt.push(15);
    cout<<"Front : "<<qt.front()<<endl;
    qt.pop();
    cout<<"Front : "<<qt.front()<<endl;
    qt.pop();
    cout<<"Front : "<<qt.front()<<endl;
    qt.pop();
    cout<<"Front : "<<qt.front()<<endl;
    qt.pop();
    cout<<"Front : "<<qt.front()<<endl;
    cout<<"Empty : "<<qt.isEmpty()<<endl;
    cout<<endl;






    return 0;
}