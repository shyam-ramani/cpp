#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};
void print(Node* root,queue<Node*> q){
  if(root==NULL){
    return;
  }
  
  while(q.size()>0){
    Node* temp = q.front();
    q.pop();
    cout<<temp->data<<" ";
    if(temp->left!=NULL){
      q.push(temp->left);
    }
    if(temp->right!=NULL){
      q.push(temp->right);
    }
  }
}
int main(){
    int x;
    cin>>x;
    queue<Node*> q;
    Node* root = new Node(x);
    q.push(root);
    while(!q.empty()){
      Node* temp = q.front();
      q.pop();
      int x;
      cin>>x;
      if(x!=-1){
        temp->left = new Node(x);
        q.push(temp->left);
      }
      cin>>x;
      if(x!=-1){
        temp->right = new Node(x);
        q.push(temp->right);
      }
    }
    print(root,q);
    return 0;
}