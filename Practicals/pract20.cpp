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

void postOrderNoRec(struct Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    Node *curr = root;
    s1.push(curr);

    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);

        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty())
    {
        curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
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
    
        cout << "PostOrder sequence is : ";
        postOrderNoRec(root);
    }
    return 0;
}