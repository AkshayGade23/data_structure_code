#include "bits/stdc++.h"
using namespace std;

int sumAtKthLevel(Node *, int );

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

int sumAtKthLevel(Node *root, int k)
{
    if (root == NULL)
        return 0;

    queue<Node *> q;
    int sum = 0;
    q.push(root);
    q.push(NULL);

    while (!q.empty() && k)
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            sum += node->data;
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            k--;
            q.push(NULL);
        }
    }
    return sum;
}
int main()
{

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    // root->right->right = new Node(7);

    cout << "Sum :- "<<sumAtKthLevel(root,3);
    return 0;
}