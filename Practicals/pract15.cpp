#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insertNode(TreeNode *root, int value)
{
    if (root == NULL)
        return new TreeNode(value);

    if (value < root->val)
        root->left = insertNode(root->left, value);

    else
        root->right = insertNode(root->right, value);

    return root;
}

int getHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

void InorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;

    InorderTraversal(root->left);
    cout << root->val << " ";
    InorderTraversal(root->right);
}

int main()
{
    TreeNode *root = NULL;
    int choice;
    while (1)
    {
        cout << endl;
        cout << "1 - Insert node" << endl
             << "2 - Exit" << endl
             << "3 - Print Tree's Inorder" << endl
             << "4 - Print height of tree" << endl
             << "5 - Print count of nodes" << endl;
        cout << "Enter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value to be inserted:";
            cin >> value;
            root = insertNode(root, value);
            break;
        case 2:
            return 0;
            break;
        case 3:
            InorderTraversal(root);
            break;
        case 4:
            cout << "Height of Tree: " << getHeight(root) << endl;
            break;
        case 5:
            cout << "Count of nodes: " << countNodes(root) << endl;
            break;
        default:
            cout << "Invalid input";
        }
    }
    return 0;
}