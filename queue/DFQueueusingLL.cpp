#include<iostream>
using namespace std;

class Dnode{
    public:

    int data;
    Dnode* prev;
    Dnode* next;


    Dnode(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Dnode(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Destructor called for value : "<<val<<endl;
    }
};

class DoublyEndedQueue{
    Dnode* head;
    Dnode* tail;
    public:

    DoublyEndedQueue(){
        head=NULL;
        tail=NULL;
    }



    void push_back(int val){
        Dnode* temp =new Dnode(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }

    }
    void push_front(int val){
        Dnode* temp =new Dnode(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

    }

    void pop_front(){
        if(head==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        else{
            Dnode* temp=head;
            if(head==tail){
                head=NULL;
                tail=NULL;
                delete temp;
                return;

            }
            //Dnode* temp=head;
            head=head->next;
            if(head!=NULL)
                head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }

    }
    void pop_back(){
        if(head==NULL || tail==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        else{
            Dnode* temp=tail;
            if(head==tail){
                head=NULL;
                tail=NULL;
                delete temp;
                return;

            }
            //Dnode* temp=tail;
            tail=tail->prev;
            if(tail!=NULL)
                tail->next=NULL;
            temp->prev=NULL;
            delete temp;
        }

    }
    int front(){
        if(head==NULL){
            cout<<"No element in Queue "<<endl;
            return -1;
        }
        return head->data;


    }
    int back(){
        if(head==NULL){
            cout<<"No element in Queue "<<endl;
            return -1;
        }
        return tail->data;


    }

    bool isEmpty(){
        if(head==NULL){
            return true;
        }
         return false;

    }

    void printQueue(){
        if(head==NULL){
            cout<<"No elemet present in queue"<<endl;
            return;
        }
        Dnode* temp=head;
        while(temp!=NULL){
            cout<<'['<<temp->data<<']'<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void flush(){
        cout<<"Flush function called "<<endl;
        delete head;
    }
};

int main(){

    DoublyEndedQueue qt;

    qt.push_back(1);
    qt.push_front(0);
    qt.push_back(2);
    qt.push_back(3);
    qt.push_back(4);
    qt.printQueue();
   /* qt.pop_back();
    qt.pop_front();
    qt.printQueue();
    cout<<"front : " <<qt.front()<<endl;
    cout<<"back : "<<qt.back()<<endl;
    qt.pop_back();
    qt.pop_back();
    qt.pop_front();
    qt.pop_back();

    cout<<"front : " <<qt.front()<<endl;
    cout<<"back : "<<qt.back()<<endl;

    qt.push_back(1);
        cout<<"front : " <<qt.front()<<endl;
    cout<<"back : "<<qt.back()<<endl;

*/
    qt.flush();









    return 0;
    
}