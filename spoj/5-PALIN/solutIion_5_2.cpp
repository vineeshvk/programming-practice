//not my solution
#include <bits/stdc++.h>

using namespace std;

string nextPalindrome(string str)
{
    string temp = str;

    int n = str.size();
    int half = (n - 1) / 2;

    for (int i = 0; i <= half; i++)
        str[n - i - 1] = str[i];

    if (str <= temp)
    {
        for (int i = half; i >= 0; i--)
        {
            if (str[i] != '9')
            {
                str[i]++;
                break;
            }
            str[i] = '0';
        }

        for (int i = 0; i <= (n - 1) / 2; i++)
            str[n - i - 1] = str[i];

//if 999 then it will be 000 hence change it to 1001
        if (str[0] == '0')
        {
            str[0] = '1';
            str += '1';
        }
    }

    return str;
}

int main()
{
    long long  t;
    cin >> t;
    cout<< t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        cout << nextPalindrome(str) << "\n";
    }
    return 0;
}