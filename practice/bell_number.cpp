// n = 2 ; no of ways = 2;  {1, 2};    { {1}, {2} } { {1, 2} }

#include <iostream>
using namespace std;

int bellNumber(int n)
{
    int bell[n + 1][n + 1];
    bell[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        bell[i][0] = bell[i - 1][i - 1];
        for (int j = 1; j <= i; j++)

            bell[i][j] = bell[i - 1][j - 1] + bell[i][j - 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << bell[i][j] << " ";
        }
        cout << "\n";
    }
    return bell[n][0];
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        cout << bellNumber(n) << "\n";
    }
    return 0;
}