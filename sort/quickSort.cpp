#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[high]);
    return i;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,9); 
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}