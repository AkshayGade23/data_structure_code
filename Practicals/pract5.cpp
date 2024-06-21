#include <bits/stdc++.h>
using namespace std;

int my_binary_search(int *arr, int n, int sv)
{
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == sv)
        {
            return mid;
        }
        else if (arr[mid] > sv)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// using recursion
int using_recursion_binary_search(int *arr, int st, int ed, int sv)
{
    int l = st, r = ed;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == sv)
        {
            return mid;
        }
        else if (arr[mid] > sv)
            return using_recursion_binary_search(arr, l, mid - 1, sv);
        else
            return using_recursion_binary_search(arr, mid + 1, r, sv);
    }
    return -1;
}


int main()
{
    int arr[100];
    int n, data;
    cout << "\nEnter no of elements:";

    cin >> n;
    cout << "\nEnter Elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\n Enter Search value:";
    cin >> data;

    int temp = using_recursion_binary_search(arr, 0, n-1, data);
    if (temp !=-1 )
        cout << "\n \n Element found at " << temp << " position";
    else
        cout << "\n Element not found";
}