#include<iostream>
using namespace std;
int main(){
    int arr[5]={5,2,3,2,5};
    for(int i=0;i<4;i++){
        int mini=INT_MAX;
         int idx=-1;
        for(int j=i;j<5;j++){
            if(mini>arr[j]){
                mini=arr[j];
                idx=j;
            }
        }
        int temp=arr[idx];
        arr[idx]=arr[i];
        arr[i]=temp;
    }
    for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
}

    
}