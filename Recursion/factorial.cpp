#include<iostream>
using namespace std;
long long factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    int num=10;
    long long fact=factorial(num);
    cout<<fact<<endl;
    cout<<LONG_LONG_MAX<<endl;
    return 0;
}