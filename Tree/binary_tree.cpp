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

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrderNoRec(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

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

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

int countNodes(Node *root)
{
    if (!root)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sum(Node *root)
{
    if (!root)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
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

    // preOrder(root);
    // cout << endl;
    postOrderNoRec(root);
    // postOrder(root);
    // cout << endl;

    // levelOrder(root);

    // cout << endl
    //      << countNodes(root) << " " << sum(root);

    return 0;
}

