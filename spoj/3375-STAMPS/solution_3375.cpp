#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int rayStamps, n;
        cin >> rayStamps >> n;

        int friendStamps[n];

        for (int i = 0; i < n; i++)
            cin >> friendStamps[i];

        sort(friendStamps, friendStamps + n);

        int i = n - 1;
        int count = 0;
        while (i >= 0 && rayStamps > 0)
        {
            count++;
            rayStamps -= friendStamps[i];
            i--;
        }
        cout << "Scenario #" << (t + 1) << ":\n";

        if (rayStamps <= 0)
            cout << count;
        else
            cout << "impossible ";
        cout << "\n";
    }
    return 0;
}