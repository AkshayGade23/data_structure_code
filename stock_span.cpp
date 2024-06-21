#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stock_span(vector<int> a)
{
    stack<pair<int, int>> st;
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        int days = 1;

        while (!st.empty() and st.top().first <= a[i])
        {
            days += st.top().second;
            st.pop();
        }
        st.push({a[i], days});
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    vector<int> prices = { 90, 80, 85, 60, 56, 90};
    vector<int> result = stock_span(prices);
    for (auto re : result)
    {
        cout << re << " ";
    }
}