#include<iostream>
using namespace std;
int power(int a,int b){
  //base case
  if(b==0)
    return 1;
  if(b==1)
    return a;
  //handling case with recursive call
  if(b&1)
    return a*(power(a,b/2)*power(a,b/2));
  else
    return (power(a,b/2)*power(a,b/2));
}
