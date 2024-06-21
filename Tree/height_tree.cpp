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
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// Intuition
//   recursive approch
//   calcualte height of left side of tree
//   calculate height of right side of tree
//   return max(left,right) + 1

int calculate_height(Node *root)
{
    return !root ? 0 : max(calculate_height(root->left), calculate_height(root->right)) + 1;
}

// Intuition
// recursive approach
// calculate height of right and left subtree 
// if diameter id going through current node then return left_height + right_height+1
// else return max(leftDiameter,rightDiameter)

int calculate_diameter(Node *root)
{
    
    return !root ? 0 : max((calculate_height(root->left)+ calculate_height(root->right) + 1), max(calculate_diameter(root->left), calculate_diameter(root->right)));
}

int sum_replacement(Node* root){
    if(!root) return 0;
    root->data += sum_replacement(root->left) + sum_replacement(root->right);
    
    return root->data;
}

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->left->left = new Node(5);
    root->left->left->left->left = new Node(6);
    root->left->left->left->left->left = new Node(8);
    // root->right->right = new Node(4);
    // root->right->right->right = new Node(5);
    // root->right->right->right->right = new Node(6);
    // root->right->right->right->right->right = new Node(8);

     inOrder(root);
     sum_replacement(root);
     inOrder(root);

    return 0;
}