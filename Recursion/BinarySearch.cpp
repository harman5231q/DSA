#include<iostream>
using namespace std;
int binarySearch(int *arr,int s,int e,int key){
  if(s>e)
    return -1;

  int m=(s+e)>>1;
  if(arr[m]==key)
    return m;

  if(key>arr[m])
    return binarySearch(arr,m+1,e,key);
  else
    return binarySearch(arr,s,m-1,key);
}