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

void flatten(Node *root)
{
    static Node *prev = NULL;

    if (!root)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;

    // if (!root || (!root->left && !root->right))
    //     return;
    // if (root->left)
    // {
    //     Node *temp = root->right;

    //     root->right = root->left;
    //     root->left = NULL;

    //     flatten(root->right);
    //     Node *tail = root->right;
    //     while (tail->right != NULL)
    //         tail = tail->right;

    //     tail->right = temp;
    //     flatten(tail->right);
    // }
    // else
    //     flatten(root->right);
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

    preOrder(root);
    cout << endl;

    flatten(root);

    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }

    return 0;
}