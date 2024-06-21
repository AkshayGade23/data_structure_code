#include <iostream>
using namespace std;
#define n 10

class stack
{
    int *arr;
    int top;

    stack()
    {
        arr = new int[n];
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
    bool isFull()
    {
        if (top == n)
            return true;

        return false;
    }
    void push(int x)
    {
        if (isFull())
            cout << "Stack is full" << endl;

        else 
            arr[++top] = x;
    }
    int pop()
    {
        if (isEmpty())
            cout << "No element to pop" << endl;
        else
            return arr[top--];
    }
};

int main()
{
    return 0;
}