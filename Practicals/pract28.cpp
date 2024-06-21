#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist
{
    Node *head;

public:
    Linkedlist() { head = NULL; }
    void insertNode(int, int);
    void printList();
    void deleteNode(int);
};
void Linkedlist::deleteNode(int index)
{
    Node *tempNode = head;
    Node *tempNode2;
    // Can't delete from empty Linked List
    if (head == NULL)
    {
        cout << ("\nEmpty List, can't delete");
    }
    if (index < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (index == 1)
    {
        tempNode = head;
        head = tempNode->next;
        cout << "\nValue Deleted: " << (tempNode)->data << endl;
        free(tempNode);
    }
    else if (tempNode->next == NULL)
    {
        cout << "\nValue Deleted: " << (head)->data << endl;
        free(head);
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            tempNode2 = tempNode;
            tempNode = tempNode->next;
            if (tempNode == NULL)
            {
                printf("\nCan't delete");
                return;
            }
        }
        tempNode2->next = tempNode->next;
        cout << "\nValue Deleted: " << tempNode->data << endl;
        // delete the node at index
        free(tempNode);
    }
}
void Linkedlist::insertNode(int data, int index)
{
    // Create the new Node.
    Node *newNode = new Node(data);
    if (index < 1)
    {
        cout << "\nposition should be >= 1.";
    }
    else if (index == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < index - 1; i++)
        {
            if (temp != NULL)
            {
                temp = temp->next;
            }
        }
        if (temp != NULL)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node *temp = head;
    // Check for empty list.
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    // Traverse the list.
    cout << "\nSingly Linked List : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL";
}
// Driver Code
int main()
{
    Linkedlist list;
    int choice, i, index;
    do
    {
        cout << "\n1. Insert at position " << endl
             << "2. Delete at position " << endl
             << "3. Display " << endl
             << "4. Exit " << endl
             << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter element : " << endl;
            cin >> i;
            cout << "\nEnter position : " << endl;
            cin >> index;
            list.insertNode(i, index);
            break;
        case 2:
            cout << "\nEnter position : " << endl;
            cin >> index;
            list.deleteNode(index);
            break;
        case 3:
            list.printList();
            cout << endl;
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\nEnter correct choice" << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}