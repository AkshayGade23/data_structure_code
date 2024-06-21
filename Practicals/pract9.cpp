// C++ program to evaluate value of a postfix expression
#include <iostream>
#include <string.h>
using namespace std;
class Stack
{
public:
    int top = -1;
    // const int size = 10;
    char stack_arr[10];
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == 9)
        {
            return true;
        }
        return false;
    }
    char rettop()
    {
        return stack_arr[top];
    }
    void push(char element)
    {
        if (!isFull())
        {
            top++;
            stack_arr[top] = element;
            // cout << "element " << stack_arr[top] << " pushed successfully"
            // << endl;
            return;
        }
        cout << "Stack full cannot push" << endl;
    }
    char pop()
    {
        if (!isEmpty())
        {
            char element = stack_arr[top];
            top--;
            return element;
        }
        cout << "Stack empty cannot pop" << endl;
        return ' ';
    }
    string traverse_and_return()
    {
        string res;
        if (top >= 0)
        {
            for (int i = top; i >= 0; i--)
            {
                res += stack_arr[i];
            }
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
        return res;
    }
};
int evaluatePostfix(string exp)
{
    Stack s1;
    for (int i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            s1.push(exp[i] - '0');
        else
        {
            int val1 = s1.pop();
            int val2 = s1.pop();
            switch (exp[i])
            {
            case '+':
                s1.push(val2 + val1);
                break;
            case '-':
                s1.push(val2 - val1);
                break;
            case '*':
                s1.push(val2 * val1);
                break;
            case '/':
                s1.push(val2 / val1);
                break;
            }
        }
    }
    return s1.pop();
}
int main()
{
    string exp;
    cout << "Enter a postfix expression: ";
    cin >> exp;
    cout << "postfix evaluation: " << evaluatePostfix(exp);
    return 0;
}