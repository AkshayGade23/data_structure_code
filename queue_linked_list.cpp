#include <iostream>
using namespace std;

class node
{
    int val;

public:
    node *next;

    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    int value()
    {
        return val;
    }
};

class queue
{
public:
    node *front;
    node *back;
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);

        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue underflow";
            return;
        }
        node *toDel = front;
        front = front->next;
        delete toDel;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in Queue";
            return;
        }
        return front->value();
    }
    bool empty()
    {
        if (front == NULL)
            return true;

        return false;
    }
};

int main()
{
    return 0;
}