#include <iostream>
using namespace std;
struct Node
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
    void insertNode(int);
    void printList();
    void deleteNode();
};
void Linkedlist::deleteNode()
{
    Node *tempNode = head;
    Node *previous;
    // Can't delete from empty Linked List
    if (head == NULL)
    {
        cout << ("\nEmpty List, can't delete");
    }
    else
    {
        tempNode = head;
        head = tempNode->next;
        cout << "\nValue Deleted: " << tempNode->data << endl;
        free(tempNode);
    }
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
    newNode->next = NULL;
}

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
    int choice, i;
    do
    {
        cout << "\n1. Insert from last " << endl
             << "2. Delete from front " << endl
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