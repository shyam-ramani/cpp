#include<iostream>
using namespace std;
class node{
    public:
   int data;
   node*next;
   node(int x){
    data=x;
    next=NULL;

   }
};

node* linklist(int arr[],int index,int size){
    if(index==size){
        return NULL;
    }
    node*temp;
    temp=new node(arr[index]);
    temp->next=linklist(arr,index+1,size);
    return temp;

    

}
int main(){
        int arr[5]={1,2,3,4,5};
        node*head;
      head=linklist(arr,0,5);
      node *temp=head;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
      }

}