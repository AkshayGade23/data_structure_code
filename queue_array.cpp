#include <iostream>
using namespace std;
#define n 20
class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Overflowed Queue";
            return;
        }
        if (front == -1)
            front++;
        arr[++back] = x;
    }
    void pop()
    {
        if (front == n)
        {
            cout << "Queue limit exceeded";
            return;
        }
        if (front > back || front == -1)
        {
            cout << "No elements in queue";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front > back || front == -1)
        {
            cout << "No elements in queue";
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        if (front > back || front == -1)

            return true;

        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
cout<<q.empty();
    q.pop();

}