#include<iostream>
using namespace std;

class QueueArray{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    QueueArray(int n){
        this->size=n;
        arr=new int[size];
        rear=front=0;
    }

    void push(int data){
        //check whether queue is full
        if(rear==size){
            cout<<"Queue overflow"<<endl;
        }
        //normal flow
        else{
            arr[rear]=data;
            rear++;
        }
    }

    void pop(){
        //check if queue is empty
        if(front==rear){
            cout<<"Queue underflow"<<endl;
        }
        // noemal flow
        else{
            front++;
            if(front==rear){
                front=rear=0;
            }
        }

    }

    int qFront(){
        if(front==rear){
            cout<<"No element is present"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool isEmpty(){
        if(rear==front){
            return true;
        }
        return false;
    }
};
int main(){
    QueueArray  qt(10);
    qt.push(1);
    qt.push(2);
    qt.push(3);
    qt.push(4);
    qt.push(5);
    qt.push(6);
    qt.push(7);
    qt.push(8);
    qt.push(9);
    qt.push(10);
    //qt.push(1);
    cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
    cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
        cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
    cout<<"front : "<<qt.qFront()<<endl;
    qt.pop();
    qt.push(10);
    if(qt.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }







    return 0;
}