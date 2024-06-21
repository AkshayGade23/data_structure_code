#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Linkedlist
{
    Node *head;

public:
    Linkedlist() { head = NULL; }
    void insertNode(int);
    void printList();
    void deleteNode();
};
void Linkedlist::deleteNode()
{
    Node *tempNode = head;
    // Can't delete from empty Linked List
    if (head == NULL)
    {
        cout << ("\nEmpty List, can't delete");
        return;
    }
    // if Linked List has only 1 node
    if (tempNode->next == NULL)
    {
        cout << "\nValue Deleted: " << (head)->data << endl;
        free(head);
        return;
    }
    // else traverse to the last node
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->prev->next = NULL;
    cout << "\nValue Deleted: " << tempNode->data << endl;
    // delete the last node
    free(tempNode);
}
void Linkedlist::insertNode(int data)
{
    // Create the new Node.
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // Traverse till end of list
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Insert at the last.
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
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
    cout << "\nDoubly Linked List : " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL";
}
// Driver Code
int main()
{
    Linkedlist list;
    int choice, i;
    do
    {
        cout << "\n1. Insert at end " << endl
             << "2. Delete at end " << endl
             << "3. Display " << endl
             << "4. Exit " << endl
             << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter element to be entered : " << endl;
            cin >> i;
            list.insertNode(i);
            break;
        case 2:
            list.deleteNode();
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