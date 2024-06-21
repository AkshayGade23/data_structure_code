#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *lca(Node *root, int p, int q)
{
    if (!root)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (left && right)
        return root;
    if (!left && !right)
        return NULL;
    if (left)
        return left;
    return right;
}


int distance(Node* root,int  p, int q){
    if(!root) return 0;
    if(root->data == p or root->data == q) {
        cout << root->data  << " ";
        return 1;
    };
    
    int left = distance(root->left,p,q);
    
    int right = distance(root->right,p,q);

    if(left and right) return left + right;
    if(!left and !right) return 0;
    if(left ) return left +1;
    return right  +1;

}
int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

  cout<< distance(lca(root,4,7),4,7);
    return 0;
}