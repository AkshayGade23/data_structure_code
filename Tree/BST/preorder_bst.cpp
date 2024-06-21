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

Node *constructBstPreOrder(vector<int> preorder, int *preorderIndex, int key, int min, int max, int n)
{
    Node *root = NULL;
    cout << key << " " << *preorderIndex << endl;

    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIndex = *preorderIndex + 1;

        if (*preorderIndex < n)
            root->left = constructBstPreOrder(preorder, preorderIndex, preorder[*preorderIndex], min, key, n);

        if (*preorderIndex < n)
            root->right = constructBstPreOrder(preorder, preorderIndex, preorder[*preorderIndex], key, max, n);
    }

    return root;
}

Node *constructBstPostOrder(vector<int> postorder, int *postorderIndex, int key, int min, int max, int n)
{
    Node *root = NULL;
    cout << key << " " << *postorderIndex << endl;

    if (key > min && key < max)
    {
        root = new Node(key);
        *postorderIndex = *postorderIndex - 1;

        if (*postorderIndex < n)
            root->right = constructBstPreOrder(postorder, postorderIndex, postorder[*postorderIndex], key, max, n);

        if (*postorderIndex < n)
            root->left = constructBstPreOrder(postorder, postorderIndex, postorder[*postorderIndex], min, key, n);
    }
    return root;
}

Node *constructBst(vector<int> preorder, int size)
{
    int preIndex = 0;
    return constructBstPreOrder(preorder, &preIndex, preorder[preIndex], INT_MIN, INT_MAX, size);
}

bool isBST(Node *root, Node *min, Node *max)
{
    if (!root)
        return true;
    if (min && root->data <= min->data)
        return false;
    if (max && root->data >= max->data)
        return false;

    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

Node *sortedArrayToBST(vector<int> sortedArray, int start, int end)
{
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node(sortedArray[mid]);
    root->left = sortedArrayToBST(sortedArray, start, mid - 1);
    root->right = sortedArrayToBST(sortedArray, mid + 1, end);  
    return root;
}

int main()
{
    vector<int> preorder = {10,20,30,40,50,60,70,80};
    int preoderIndex = 0;
    Node *root = sortedArrayToBST(preorder, 0,7);
    inOrder(root);

    return 0;
}