#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

class DoublyLinkedList
{
    node *head;

public:
    DoublyLinkedList()
    {
        this->head = NULL;
    }

    void setHead(node *head)
    {
        this->head = head;
    }

    void insertAtTail(int data)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->previous = temp;
    }
    void insertAtHead(int data)
    {
        node *n = new node(data);
        if (head != NULL)
        {
            n->next = head;
            head->previous = n;
        }
        head = n;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteByValue(int val)
    {
        if (head == NULL)
            return;
        if (head->data == val)
        {
            node *temp = head;
            head = head->next;
            if (head)
                head->previous = NULL;
            free(temp);
            return;
        }
        node *current = head->next;
        node *previous = head;

        while (current->next != NULL)
        {
            if (current->data == val)
            {
                previous->next = current->next;
                current->next->previous = previous;
                break;
            }
            previous = current;
            current = current->next;
        }

        free(current);
    }
    void deleteByRank(int n)
    {
        if (head == NULL)
            return;
        if (n == 1)
        {
            node *temp = head;
            head = head->next;
            if (head)
                head->previous = NULL;
            free(temp);
            return;
        }
        node *current = head->next;
        node *previous = head;
        int i = 2;
        while (current->next != NULL && i <= n)
        {
            if (i == n)
            {
                previous->next = current->next;
                current->next->previous = previous;
                break;
            }
            previous = current;
            current = current->next;
            i++;
        }

        free(current);
    }
};

int main()
{
    DoublyLinkedList l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtHead(7);
    l.display();
    l.deleteByValue(4);
    l.deleteByRank(1);
    l.display();
    return 0;
}
