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
node *linklist(int arr[],int index,int size,node* pre){
         if(index==size){
            return pre;
         }
         node*temp;
         temp=new node(arr[index]);
         temp->next=pre;
       return linklist(arr,index+1,size,temp);
         
}

int main(){
    int arr[5]={12,34,12,432,123};
    node*head;
    head=linklist(arr,0,5,head);

int x=30;
int p=3;
p--;
node*temp1  =head;
while(p--){
    temp1 =temp1->next;
}
node *tail;
tail=new node(30);
tail->next=temp1->next;
temp1->next=tail;

    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}