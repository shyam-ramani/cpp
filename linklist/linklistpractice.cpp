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
node *linklist(int arr[],int index,int size,node* prev){
      if(index==size) return prev;
         node*temp;
       temp=new node(arr[index]);
       temp->next=prev;
       return linklist(arr,index+1,size,temp);

}
int main(){
    int arr[5]={1,2,3,43,2};
    node* head;
    head=linklist(arr,0,5,NULL);
    
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}