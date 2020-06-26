#include <iostream>
using namespace std;

long long C[100][100];
long long binomialCoefficientR(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    if (C[n][r] != 0)
        return C[n][r];

    long long total = (binomialCoefficientR(n - 1, r - 1) % 10 + binomialCoefficientR(n - 1, r) % 10) % 10;
    C[n][r] = total;

    return total;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        int sum = 0;

        for (int j = 0; j <= k; j++)
        {
            sum += binomialCoefficientR(k, j);
        }

        cout << sum << "\n";
    }
}