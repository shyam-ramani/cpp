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
Node* binarytree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* temp = new Node(x);
    temp->left = binarytree();
    temp->right = binarytree();
    return temp;
}
void print(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(){
    Node* root = binarytree();
    print(root);
}