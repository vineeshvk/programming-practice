#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int n;
        cin >> n;

        int sum = 0;
        int i = 0;

        do
            sum += ++i;
        while ((sum + i + 1) < n);

        bool even = i % 2 == 0;
        int x = even ? i : 0, y = even ? 0 : i;
        int sub = even ? -1 : 1;
        while (sum < n)
        {
            x += sub;
            y -= sub;
            sum++;
        }
        cout << "TERM " << n << " IS "
             << x - sub + 1 << "/" << y + sub + 1
             << "\n";
    }
}