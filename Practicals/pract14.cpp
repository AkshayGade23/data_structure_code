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

void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node *insertBST(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

Node *construtBST(Node *root, vector<int> arr)
{
    for (auto i : arr)
        root = insertBST(root, i);
    return root;
}

int main()
{
    int N;
    cout << "Enter number of Nodes : ";
    cin >> N;

    vector<int> nodes(N);
    for (int i = 0; i < N; i++)    
        cin >> nodes[i];


    Node *root = NULL;
    root = construtBST(root, nodes);

    cout << "\nPreorder Traversal : ";
    preOrder(root);
    cout << "\nInorder Traversal : ";
    inOrder(root);
    cout << "\nPostorder Traversal : ";
    postOrder(root);

    return 0;
}
