#include <iostream>

using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    if (n == 1 || s[0] == s[n - 1])
        return true;
    if (!isPalindrome(s.substr(1, n - 2)))
        return false;
}

string reverseString(string s)
{
    int n = s.length();
    if (n == 1)
        return string(1, s[n - 1]);

    if (n == 2)
        return string(1, s[n - 1]) + s[0];

    return s[n - 1] + reverseString(s.substr(1, n - 2)) + s[0];
}

int sumOfDigits(int n)
{
    if (n / 10 == 0)
        return n;
    return n % 10 + sumOfDigits(n / 10);
}

void towerOfHonoi(int n, string src, string dest, string help)
{
    if (n == 0)
        return;

    towerOfHonoi(n - 1, src, help, dest);
    cout << "From " << src << " to " << dest << endl;
    towerOfHonoi(n - 1, help, dest, src);
}

string removeDuplicateLetters(string s)
{
    if (s.length() <= 1)
        return s;

    string nDup = removeDuplicateLetters(s.substr(1));
    if (s[0] == nDup[0])
        return nDup;

    return s[0] + nDup;
}

int main()
{
towerOfHonoi(5,"A","C","B");
    return 0;
}