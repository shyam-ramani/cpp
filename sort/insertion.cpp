#include<bits/stdc++.h>
using namespace std;
void heapify(int idx,int arr[],int n){
    int largest=idx;
    int left=2*idx+1;
    int right=2*idx+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=idx){
        swap(arr[largest],arr[idx]);
        heapify(largest,arr,n);
    }
}
void helper(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
}
void heapsort(int arr[],int n){
    for(int i=n-1; i>0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}
int main(){
    int arr[10]={5,4,3,22,12,81,90,95,99,87};
    int n=10;
   helper(arr,n);
   heapsort(arr,n);
     for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
}
}