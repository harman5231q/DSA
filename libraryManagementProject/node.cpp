#include<iostream>
using namespace std;
class Node{
    public:
    string name;
    bool available;
    int code;
    Node* next;
    
    Node(){

    }
    Node(int num){
        this->code=num;
        this->name="No book name provided";
        this->available=true;
        this->next=NULL;
    }
    Node(int code,string str){
        this->code=code;
        this->name=str;
        this->available=true;
        this->next=NULL;
    }
    ~Node(){
        int value=this->code;
        // if node is pointing to some value
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"destructor called  for : "<<value<<endl;
    }

    


};