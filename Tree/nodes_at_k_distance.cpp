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


// case 1  
void printSubtreeNodes(Node *root, int k)
{
    if (!root || k< 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

// case 2 

int printNodesAtK(Node * root,Node* target ,int k){
    if(!root) return -1;

    if(root == target) return 0;
    

    // if target find in left tree
    int dl = printNodesAtK(root->left,target,k);
    if(dl !=-1 ){
        if (dl +1 == k) cout << root->data << " ";

        else {
            printSubtreeNodes(root->right,k-dl-2);
        }
        return dl+1;
    }

    // if target find in right tree
    int dr = printNodesAtK(root->right,target,k);
    if(dr !=-1 ){
        if (dr +1 == k) cout << root->data << " ";

        else {
            printSubtreeNodes(root->left,k-dr-2);
        }
        return dr+1;
    }

    return -1;
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

    

    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }

    return 0;
}