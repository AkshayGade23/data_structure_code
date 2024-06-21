#include <iostream>
#include <stack>
using namespace std;

bool redundant_paranthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' and s[i] <= 'z') or s[i] >= 'A' and s[i] <= 'z') continue;
        
        if (s[i] != ')') st.push(s[i]);
        
        else {
            if (st.top() == '(') return true;

            while (!st.empty() and (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/'))
                st.pop();
            
            st.pop();
        }
    }
    return false;
}
int main()
{ 
    string s ="((a+b)+c)";
    cout<<redundant_paranthesis(s); 
}