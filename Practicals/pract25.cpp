#include <bits/stdc++.h>
using namespace std;

int ternar_search(int *arr, int n, int data)
{
    int l = 0, r = n - 1;
    while (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == data)
            return mid1;

        if (arr[mid2] == data)
            return mid2;

        if (data < arr[mid1])
            r = mid1 - 1;
        else if (data > arr[mid2])
            l = mid2 + 1;
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
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
    
    int temp = ternar_search(arr, n, data);
    if (temp != -1)
        cout << "\n \n Element found at " << temp << " position";
    else
        cout << "\n Element not found";
}