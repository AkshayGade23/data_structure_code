#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Stack
{
public:
    int top = -1;
    vector<Node *> stack_arr;
    Node *rettop()
    {
        return stack_arr[top];
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    void push(Node *element)
    {
        top++;
        stack_arr.push_back(element);
    }
    Node *pop()
    {
        if (!isEmpty())
        {
            Node *element = stack_arr[top];
            top--;
            stack_arr.pop_back();
            return element;
        }
        cout << "Stack empty cannot pop" << endl;
        return NULL;
    }
};
void printInorder(Node *root)
{
    Stack s1;
    Node *curr = root;
    while (!s1.isEmpty() || curr != NULL)
    {
        // cout<<curr->data;
        while (curr != NULL)
        {
            s1.push(curr);
            curr = curr->left;
        }
        curr = s1.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(7);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->left->left->left = new Node(6);
    printInorder(root);
    return 0;
}