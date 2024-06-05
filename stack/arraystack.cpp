#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
    public:
    Stack(){

    }
    Stack(int size){
        this->size=size;
        arr=new int[this->size];
        top=-1;
    }

    

    void push(int val){
        if(size-top>1){
            top++;
            arr[top]=val;

        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<< "Stack underflow"<<endl;
        }

    }

    int peak(){
        if(top>=0){
            return arr[top];
        }
        cout<<"No element is present in stack"<<endl;
        return -1;
    }
    bool empty(){
        if(top==-1){
            return true;
        }

        return false;

    }

};
int main(){
    Stack st(4);
    cout<<"Peak : "<<st.peak()<<endl;
    st.push(1);
    cout<<st.peak()<<endl;
    st.push(2);
    cout<<st.peak()<<endl;
    st.push(3);
    cout<<st.peak()<<endl;
    st.push(4);
    cout<<st.peak()<<endl;
    st.push(5);
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



}