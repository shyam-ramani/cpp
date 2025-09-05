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
void print(Node* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  print(root->left);
  print(root->right);
 
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
    print(root);
    return 0;
}