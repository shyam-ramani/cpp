#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};
int getheight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}
Node *rightrotate(Node *root)
{
    Node*child = root->left;
    Node*childright = child->right;
    child->right = root;
    root->left = childright;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;

}
Node *leftrotate(Node *root)
{
    Node*child = root->right;
    Node*childleft = child->left;
    child->left = root;
    root->right = childleft;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}


Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int balance = getheight(root->left) - getheight(root->right);
    if (balance > 1 && key < root->left->data)
    {
        return rightrotate(root);
    }
    if (balance < -1 && key > root->right->data)
    {
        return leftrotate(root);
    }
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);

    return 0;
}