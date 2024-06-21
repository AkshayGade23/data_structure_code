//  building binary tree using preorder and inorder
//  building binary tree using postorder and inorder

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
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == curr)
            return i;
    return -1;
}

Node *buildBTPreIn(int preorder[], int inorder[], int start, int end)
{
    static int ind = 0;

    if (start > end)
        return NULL;

    int curr = preorder[ind++];
    Node *node = new Node(curr);

    int pos = search(inorder, start, end, curr);
    node->left = buildBTPreIn(preorder, inorder, start, pos - 1);
    node->right = buildBTPreIn(preorder, inorder, pos + 1, end);

    return node;
}

Node *buildBTPostIn(int postorder[], int inorder[], int start, int end)
{
    static int ind = 6;

    if (start > end)
        return NULL;

    int curr = postorder[ind--];

    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = search(inorder, start, end, curr);
    node->right = buildBTPostIn(postorder, inorder, pos + 1, end);
    node->left = buildBTPostIn(postorder, inorder, start, pos - 1);

    return node;
}


int main()
{
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};

    Node *root = buildBTPostIn(postorder, inorder, 0, 6);
    preOrder(root);
    return 0;
}