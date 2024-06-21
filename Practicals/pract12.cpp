#include <iostream>
using namespace std;
// Node structure
struct Node
{
    int data;
    Node *next;
};


// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// Function to insert a new node at the front of the list
void insertAtFront(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


// Function to delete a node with a given value
void deleteNode(Node **head, int data)
{
    Node *current = *head;
    Node *prev = NULL;
    if (current != NULL && current->data == data)
    {
        *head = current->next;
        delete current;
        return;
    }
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    prev->next = current->next;
    delete current;
}


// Function to display the list
void displayList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main()
{
    Node *head = NULL;
    insertAtFront(&head, 9);
    insertAtFront(&head, 7);
    insertAtFront(&head, 8);
    insertAtFront(&head, 5);
    insertAtFront(&head, 3);
    insertAtFront(&head, 1);
    cout << "Original List: ";
    displayList(head);
    deleteNode(&head, 3);
    deleteNode(&head, 8);
    cout << "List after deletion: ";
    displayList(head);
    return 0;
}
