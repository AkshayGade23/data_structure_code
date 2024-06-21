
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

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *searchInBST(Node *root, int x)
{
    if (!root)
        return NULL;

    if (root->data == x)
        return root;

    if (x < root->data)
        return searchInBST(root->left, x);
    return searchInBST(root->right, x);
}

void zigzagTraversal(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    bool leftToright = false;
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        if (leftToright)
        {
            while (!s2.empty())
            {
                Node *top = s2.top();
                s2.pop();
                cout << top->data << " ";
                if(top->right)s1.push(top->right);
                if(top->left)s1.push(top->left);
            }
            leftToright = false;
        }
        else
        {
            while (!s1.empty())
            {
                Node *top = s1.top();
                s1.pop();
                cout << top->data << " ";
                if(top->left)s2.push(top->left);
                if(top->right)s2.push(top->right);
            }
            leftToright = true;
        }
    }
}

Node *inOrderSuccessor(Node *root)
{
    return root->left ? inOrderSuccessor(root->left) : root;
}

Node *deleteInBST(Node *root, int x)
{
    if (!root)
        return NULL;
    if (root->data > x)
        root->left = deleteInBST(root->left, x);
    else if (root->data < x)
        root->right = deleteInBST(root->right, x);
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (!root->right)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {

            Node *successor = inOrderSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteInBST(root->right, successor->data);
        }
    }
    return root;
}

int main()
{
    vector<int> nodes = {4, 3, 7, 6, 10, 9, 15};
    Node *root = NULL;
    root = construtBST(root, nodes);
    // inOrder(root);
    zigzagTraversal(root);
    return 0;
}
