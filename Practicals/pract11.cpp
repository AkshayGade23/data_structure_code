#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseStack(stack<int> &s)
{
    queue<int> q;
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(7);
    s.push(3);
    s.push(9);
    cout << "Original stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.push(5);
    s.push(7);
    s.push(3);
    s.push(9);
    reverseStack(s);
    cout << "Reversed stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}