#include <bits/stdc++.h>
using namespace std;

int noOfSteps(int n)
{
    int stari, starj;

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                stari = j;
                starj = k;
            }
        }
    }
    int mid = n / 2;
    int result = abs(mid - stari) + abs(mid - starj);
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << noOfSteps(n) << "\n";
    }
    return 0;
}