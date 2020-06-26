// 11(9091a + 910b + 100c) palindrome formula
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(long long n)
{
    string strN = to_string(n);
    string strR = strN;
    reverse(strR.begin(), strR.end());
    return strN == strR;
}
int main()
{
    int start = clock();

    int digits = 3;
    int below = pow(10, digits);
    int above = pow(10, digits - 1);
    int max = 0;
    for (int i = above; i < below; i++)
    {
        for (int j = above; j < below; j++)
            if (isPalindrome(i * j) && i * j > max)
            {
                max = i * j;
            }
    }
    cout << max << "\n";

    int end = clock();
    cout << ((float)end - start) / CLOCKS_PER_SEC << "seconds.";
}
