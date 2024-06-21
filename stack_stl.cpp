#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &, int);
void reverse(stack<int> &);
void reverseSentence(string);
int prec(char);
string infixToPostfix(string);
string infixToPrefix(string);
bool isValidParanthesis(string);

void insertAtBottom(stack<int> &st, int elem)
{
    if (st.empty())
    {
        st.push(elem);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);
    st.push(topElem);
}

void reverse(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }
    int elem = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, elem);
}
void reverseSentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string words = "";

        while (s[i] != ' ' && i < s.length())
            words += s[i++];

        st.push(words);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];

        else if (s[i] == '(')
            st.push(s[i]);

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == ')')
            st.push(s[i]);

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

bool isValidParanthesis(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (!st.empty() && (s[i] == ')' && st.top() != '(') || (s[i] == '}' && st.top() != '{') || (s[i] == ']' && st.top() != '['))
                return false;
            else
                st.pop();
        }
    }
    return st.empty() ? true : false;
}

int main()
{
    string equ = "{a+(a-c+[j+r])}";
    if (isValidParanthesis(equ))
        cout << "It is valid";

    else
        cout << "It is invalid";

    return 0;
}
