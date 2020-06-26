#include <bits/stdc++.h>
using namespace std;

long long jerryWins(long long TS)
{
    while (TS % 2 == 0)
        TS /= 2;

    return TS / 2;
}

int main()
{
    int test = 1;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        long long TS;
        cin >> TS;
        long long jerry = jerryWins(TS);
        cout << jerry << "\n";
    }

    return 0;
}