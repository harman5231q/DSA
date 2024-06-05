#include<iostream>
using namespace std;

class DoublyEndedQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    DoublyEndedQueue(int n){
        this->size=n;
        arr=new int[size];
        front=rear=-1;

    }

    void printQueue(){
        cout<<" front : "<<front<<endl;
        cout<<" rear : "<<rear<<endl;

        for(int i=0;i<size;i++){
            cout<<arr[i]<<"->";
        }
        cout<<endl;
    }

    void push_front(int val){
        // check for empty space
        if((front==0 && rear==size-1)|| ((front!= 0 &&size!=1) && rear==(front-1)%(size-1))){
            cout<<"Queue overflow"<<endl;
            return;
        }
        //no element present
        else if(front==-1){
            front=rear=0;
        }
        //front is at first position and empty space available
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        //normal execution
        else{
            front--;
        }

        arr[front]=val;

    }

    void push_back(int val){
        // check for empty space
        if((front==0 && rear==size-1)|| ((front!= 0 &&size!=1) && rear==(front-1)%(size-1))){
            cout<<"Queue overflow"<<endl;
            return;
        }
        //no element present
        else if(front==-1){
            front=rear=0;
        }
        //rear is at last position and empty space available
        else if(front !=0 && rear==size-1){
            rear=0;
        }
        //normal execution
        else{
            rear++;
        }

        arr[rear]=val;
        
    }

    void pop_front(){
        //no element is present
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        int val=arr[front];
        arr[front]=-1;
        //only element present
        if(front==rear){
            front=rear=-1;
        }
        //front is pointing at last it moves to start of array
        else if(front==size-1){
            front=0;
        }
        //normal execution
        else{
            front++;
        }
        cout<<val<<"  has been removed from Queue"<<endl;
    }

    void pop_back(){
        //no element
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        int val=arr[rear];
        arr[rear]=-1;
        //only element
        if(front==rear){
            front=rear=-1;
        }
        // rear is at 0th  position it moves to the last
        else if(rear==0 ){
            rear=size-1;
        }
        //normal execution
        else{
            rear--;
        }
        cout<<val<<"  has been removed from Queue"<<endl;

    }
    int qFront(){
        if(front==-1){
            cout<<"No element present in queue"<<endl;
            return -1;
        }

        return arr[front];

    }

    int qRear(){
        if(front==-1){
            cout<<"No element present in queue"<<endl;
            return -1;
        }

        return arr[rear];

    }
    bool isFull(){
        if((front==0 && rear==size-1)|| ((front!= 0 &&size!=1) && rear==(front-1)%(size-1))){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }
};

int main(){
    DoublyEndedQueue obj(1);


    obj.push_back(2);
   
    obj.push_back(3);
    obj.push_front(1);
    obj.push_front(0);
    //obj.push_back(4);
    cout<<obj.qFront()<<endl;
    cout<<"full : "<<obj.isFull()<<endl;
    //obj.push_back(2);
    //obj.push_front(2);
    //obj.pop_front();
    obj.pop_back();
    obj.push_front(2);
    cout<<obj.qFront()<<endl;
    obj.printQueue();


    
}