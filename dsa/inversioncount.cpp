#include<bits/stdc++.h>
using namespace std;
int m(vector<int>&arr,int st,int mid,int en){
    vector<int>temp;
    int count=0;
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
      count+=mid-i+1;
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
  return count;
}
int merge(vector<int>&arr,int st,int en){
    if(st<en){
        int mid=st+(en-st)/2;
        int x=merge(arr,st,mid);
        int y=merge(arr,mid+1,en);
        int z=m(arr,st,mid,en);
        return x+y+z;
    }
     return 0;
}
int main(){
    vector<int>arr={6,2,3,7,8,5,1};
    int count=merge(arr,0,arr.size()-1);
    cout<<count<<endl;
}