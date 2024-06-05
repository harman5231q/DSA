#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    CircularQueue(int n){
        this->size=n;
        arr=new int[size];
        front=rear=-1;

    }

    void push(int val){
        if((front==0 && rear==size-1)|| ((front!= 1 &&size!=1) && rear==(front-1)%(size-1))){
            cout<<"Queue overflow"<<endl;
            return;
        }
        else if(front==-1){
            front=rear=0;
        }
        else if(front !=0 &&rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }

        arr[rear]=val;
        
    }

    void pop(){
        if(front==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        int val=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
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

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }



    void print(){
        cout<<"printing queue : "<<endl;

        for(int i=0; i<size ;i++){
            cout<<'['<<arr[i]<<']'<<"->";
        }cout<<endl;

        cout<<"front : "<<front<<endl;
        cout<<"Rear : "<<rear<<endl;
    }
};
int main(){
    CircularQueue obj(1);
/*
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    //obj.push(6);
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();
    cout<<"front : "<<obj.qFront()<<endl;
    obj.pop();

    cout<<"Empty : "<<obj.isEmpty()<<endl;


*/
        obj.push(1);
        obj.push(2);
        obj.print();




    return 0;
}