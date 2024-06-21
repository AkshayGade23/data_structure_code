// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// void Tshirt(char first[], char second[], int p1x, int p2x, char c1, char c2)
// {
//     int p1 = sizeof(first) / sizeof(*first);
//     int p2 = sizeof(second) / sizeof(*second);

//     if (first[0] == '\0' && second[0] == '\0')
//     {

//         if (c1 > c2)

//             cout << "<";

//         else if (c1 < c2)
//         {
//             cout << ">";
//         }

//         else if (c1 == c2)
//         {
//             if (p1x == p2x)
//                 cout << "=";

//             else if (c1 == 'l')
//             {
//                 if (p1x > p2x)
//                     cout << ">";
//                 else
//                     cout << "<";
//             }

//             else if (c1 == 's' || c1 == 'm')
//             {
//                 if (p1x > p2x)
//                     cout << "<";

//                 else
//                     cout << ">";
//             }
//         }
//     }

//     if (first[0] != '\0' && second[0] != '\0')
//     {
//         if (first[0] == 'x')
//             p1x++;

//         if (second[0] == 'x')
//             p2x++;

//         if (first[0] == 's' || first[0] == 'm' || first[0] == 'l')
//             c1 = first[0];

//         if (second[0] == 's' || second[0] == 'm' || second[0] == 'l')

//             c2 = second[0];
//     }
//     if (first[0] != '\0')
//     {
//         if (first[0] == 'x')
//             p1x++;

//         else if (first[0] == 's' || first[0] == 'm' || first[0] == 'l')
//             c1 = first[0];
//     }
//     if (second[0] != '\0')
//     {
//         if (second[0] == 'x')
//             p2x++;

//         else if (second[0] == 's' || second[0] == 'm' || second[0] == 'l')
//             c2 = first[0];
//     }
//     Tshirt(first + 1, second + 1, p1x, p2x, c1, c2);
// }

// int main()
// {
//     int t;
//     char c1, c2;
//     cin >> t;
//     while (t--)
//     {
//         char first[100], second[100];
//         cin >> first;
//         cin >> second;
//         Tshirt(first, second, 0, 0, c1, c2);
//     }
//     return 0;
// }

#include <iostream>
#include <string.h>
using namespace std;
class Stack
{
public:
    int top = -1;
    // const int size = 10;
    int stack_arr[25];
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
        if (top == 24)
        {
            return true;
        }
        return false;
    }
    char rettop()
    {
        return stack_arr[top];
    }
    void push(int element)
    {
        if (!isFull())
        {
            top++;
            stack_arr[top] = element;
            return;
        }
        cout << "Stack full cannot push" << endl;
    }
    int pop()
    {
        if (!isEmpty())
        {
            int element = stack_arr[top];
            top--;
            return element;
        }
        cout << "Stack empty cannot pop" << endl; 
        return ' ';
    }
};
int evaluatePostfix(string exp)
{
    Stack s1;
    for (int i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i])){
            s1.push(exp[i] - '0');
        }
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
