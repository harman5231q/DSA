#include<iostream>
using namespace std;
int partition(int *arr,int s,int e){
    int pivot=arr[s];
    int count =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)
            count++;
    }
    int pivotid=s+count;
    swap(arr[pivotid],arr[s]);
    while(s<pivotid && pivotid<e){
        while(arr[s]<pivot){
            s++;
        }
        while(arr[e]>pivot){
            e--;
        }
        if(s<pivotid && e>pivotid){
            swap(arr[s++],arr[e--]);
        }
    }
    return pivotid;
}
void quickSort(int *arr,int s,int e){
    cout<<"entry in quicksort"<<endl;
    if(s>=e)
        return;
    int pivot=partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}

int main() {
  int array[]={8,1,3,5,2,4,7,9,6,4,2,3,4,5,6,1};
  quickSort(array,0,15);
  for(int i=0;i<16;i++)
      cout<<array[i]<<" ";
  cout<<endl;
  return 0;
}