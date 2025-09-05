#include<iostream>
using namespace std;
class node{
    public:
   int data;
    node *next;
node(int x){
    data=x;
    next=NULL;
}
};



int main(){
    node*head,*tail;
    head=NULL;
    
    int arr[5]={32,45,34,23,1};
    for(int i=0;i<5;i++){
    if(head==NULL){
        head=new node(arr[i]);
        tail=head;
    }
          
    else{
       tail->next=new node(arr[i]);
       tail=tail->next ;
    }
    
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}