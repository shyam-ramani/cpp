#include<bits/stdc++.h>
using namespace std;
void heapify(int i,int arr[],int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(largest,arr,n);
    }

}
void helper(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }
}
void heapSort(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main(){
    int arr[10]={1,2,4,5,71,3,22,45,57,55};
    helper(arr,10);
    heapSort(arr,10);
        for(int i=0;i<10;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
        
    
}