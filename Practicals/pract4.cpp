#include <iostream>
#include <stdio.h>
using namespace std;
int get_fib(int);
int main()
{
    int S[10];
    //= { 5, 23, 34, 42, 48, 54, 65, 75, 81, 95 };
    int n, key, index, low, high, loc, flag;
    n = 10;
    low = 0;
    int location = -1;
    high = n - 1;
    flag = 0; // Read the key
    cout << "Enter the Elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    cout << "Enter Key To Search:";
    cin >> key;
    index = 0;
    while (flag != 1 && low <= high)
    {
        index = get_fib(n);
        if (key == S[index + low])
        {
            location = low + index;
            flag = 1;
            break;
        }
        else if (key > S[index + low])
        {
            low = low + index + 1;
        }
        else
        {
            high = low + index - 1;
        }
        n = high - low + 1;
    }
    if (flag == 1)
    {
        cout << "Element Found at Index " << location + 1 << endl;
    }
    return 0;
}
int get_fib(int n)
{
    int fibk = 0;
    int fibk2 = 0;
    int fibk1 = 1;
    if (n == 0 || n == 1)
    {
        return 0;
    }
    while (fibk < n)
    {
        fibk = fibk1 + fibk2;
        fibk2 = fibk1;
        fibk1 = fibk;
    }
    return fibk2;
}