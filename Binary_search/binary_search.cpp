#include <iostream>
#include <stdlib.h>
using namespace std;

int binary_searchRRR(int *arr, int low, int high, int key)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            return binary_searchRRR(arr, low, mid - 1, key);

        return binary_searchRRR(arr, mid + 1, high, key);
    }
    return -1;
}

int binary_search(int *arr, int n, int key)
{
    int high = n-1, low = 0, mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == key)
            return mid;
        
        else if (arr[mid] > key)
            high = mid - 1;

        else if (arr[mid] < key)
            low = mid + 1;
    }
    return -1;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int arr2[100];
    // for (int i = 0; i < 100; i++)
    // {w
    //     arr2[i] = i;
    // }

    int *ptr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    ptr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        *(ptr+i) = i;
    }
    

    int result = binary_search(ptr, n, 66);

    if (result)
    {
        cout << "Key Found at position " << result;
    }
    else
        cout << "Key not found";
    free(ptr);
    return 0;
}