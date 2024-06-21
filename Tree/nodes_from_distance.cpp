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

void printNodesInSubtree(Node* root,int k){
    if(!root || k < 0)return ;

    if(k == 0){
        cout << root->data << " ";
        return;
    }
    printNodesInSubtree(root->left,k-1);
    printNodesInSubtree(root->right,k-1);
}
int main()
{

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

   

    return 0;
}
