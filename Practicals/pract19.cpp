#include "bits/stdc++.h"
using namespace std;
#define N 20;

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

void preOrderNoRec(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        curr = curr->right;
    }
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



int main()
{
    int i = 0;
    int values[20];
    cout << "Enter values to be insert in BST: \n";
    while (i < 20)
    {
        int choice;
        cout << "\n[ 1. Add Value, 2. Exit ] : ";
        cin >> choice;

        if (choice == 1)
            cin >> values[i++];

        else
            break;
    }

    if (i <= 0)
        cout << "No Values in Tree";

    else
    {
        Node *root = NULL;
        for (int j = 0; j <i ; j++)    
            root = insertBST(root, values[j]);
    
        cout << "PreOrder sequence is : ";
        preOrderNoRec(root);
    }
    return 0;
}