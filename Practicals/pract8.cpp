#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPrefix(string infix)
{
    stack<char> operators;
    stack<string> operands;
    string prefix = "";
    int i = 0;
    while (i < infix.size())
    {
        if (infix[i] == '(')
        {
            operators.push(infix[i]);
            i++;
        }
        else if (isdigit(infix[i]))
        {
            string operand = "";
            while (i < infix.size() && isdigit(infix[i]))
            {
                operand += infix[i];
                i++;
            }
            operands.push(operand);
        }
        else if (infix[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.pop();
            i++;
        }
        else
        {
            while (!operators.empty() && precedence(infix[i]) <=
                                             precedence(operators.top()))
            {
                string op2 = operands.top();
                operands.pop();
                string op1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.push(infix[i]);
            i++;
        }
    }
    while (!operators.empty())
    {
        string op2 = operands.top();
        operands.pop();
        string op1 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string temp = op + op1 + op2;
        operands.push(temp);
    }
    prefix = operands.top();
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string infix = "1+((2+3)*4)-5";
    cout << "Infix expression: " << infix << endl;
    cout << "Prefix expression: " << infixToPrefix(infix) << endl;
    return 0;
}