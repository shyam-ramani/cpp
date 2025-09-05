#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int st,int mid,int en){
     vector<int>temp;
     int i=st;
     int j=mid+1;
     while(i<=mid && j<=en){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
     }
     while(i<=mid){
      temp.push_back(arr[i]);
      i++;
     }
     while(j<=en){
      temp.push_back(arr[j]);
      j++;
     }
     for(int k=0;k<temp.size();k++){
        arr[k+st]=temp[k];
     }

}
  void mergesort(vector<int>&arr,int st,int en){
     if(st<en){
        int mid=(st+en)/2;
        mergesort(arr,st,mid);
        mergesort(arr,mid+1,en);

        merge(arr,st,mid,en);
     }
  }
int main(){
     vector<int>arr={6,2,3,7,8,5,1,2};
     mergesort(arr,0,arr.size()-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}