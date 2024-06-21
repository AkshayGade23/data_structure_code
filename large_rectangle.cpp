#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int rain_water_harvesting(vector<int> a)
{
    int ans = 0, n = a.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] < a[i])
        {
            int curr = st.top();
            st.pop();

            if (st.empty())
                break;
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[curr]) * diff;
        }
        st.push(i);
    }
    return ans;
}

int great_area_rectangle(vector<int> a)
{
    int n = a.size(), ans = 0, i = 0;
    a.push_back(0);
    stack<int> st;

    while (i < n)
    {
        while (!st.empty() and a[st.top()] > a[i])
        {
            int top = st.top();
            int height = a[top];
            st.pop();

            if (st.empty())
            {
                ans = max(ans, height * i);
            }
            else
            {
                ans = max(ans, height * (i - top));
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main()
{
    vector<int> a = {8, 1, 5, 6, 2, 8};
    cout << rain_water_harvesting(a);

    return 0;
}