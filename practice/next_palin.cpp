#include <bits/stdc++.h>

using namespace std;

string nextPalindromeBrute(int n)
{
    while (true)
    {
        n++;
        string strN = to_string(n);
        string revN = strN;
        reverse(revN.begin(), revN.end());

        if (revN == strN)
            return revN;
    }
}
