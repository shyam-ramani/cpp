#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
   int*arr;
   int size;
   int totalsize;

    public:
    MaxHeap(int totalsize){
        arr=new int[totalsize];
        size=0;
        this->totalsize=totalsize;
    }

    void insert(int value){
      if(size==totalsize){
          cout<<"Heap is full"<<endl;
          return;
      }
      arr[size]=value;
      int index=size;
      size++;
      while(index>0 && arr[(index-1)/2]<arr[index]){ 
          swap(arr[(index-1)/2],arr[index]);
          index=(index-1)/2;
      }
        cout<<"Inserted "<<value<<endl;
      
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
void Heapify(int index){
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=index){
        swap(arr[largest],arr[index]);
        Heapify(largest);
    }
} 
    void Delete(){
        if(size==0) {
            cout<<"Heap is empty"<<endl;
            return;
        }
        cout<<"Deleted "<<arr[0]<<endl;
        arr[0]=arr[size-1];
        size--;
        if(size==0){
            return;
        }
        Heapify(0);
    }
};
int main(){
    MaxHeap H1(6);
    H1.insert(10);
    H1.insert(20);
    H1.insert(30);
    
    H1.print();
    return 0;
}