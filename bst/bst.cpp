#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
 Node*BST(Node*root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(root->data<val){
        root->right=BST(root->right,val);
    }
    else{
        root->left=BST(root->left,val);
    }
   
    return root;
 }
 void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
 Node* del(Node*root,int val){
    if(root==NULL) return NULL ;
    if(root->data<val){
       root->right= del(root->right,val);
    }
    else if(root->data>val){
        root->left =del(root->left,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right){
            Node*child=root->right;
            delete root;
            return child;
        }
        else if(root->right==NULL && root->left){
            Node*child=root->left;
            delete root;
            return child;
        }
        else{
            Node*child=root->left;
            while(child->right!=NULL){
                child=child->right;
            }
            root->data=child->data;
            root->left=del(root->left,child->data);
            return root;
        }
            
        }
        return root;
    }

 
int main(){
     int arr[]={1,2,3,4,5,6,7};
     int n=sizeof(arr)/sizeof(arr[0]);
     Node*root=NULL;
     for(int i=0;i<n;i++){
         root=BST(root,arr[i]);
     }

    Node*temp= del(root,4);
        inorder(root);
}