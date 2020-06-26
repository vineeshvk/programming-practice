// also known as combination. n!/ ((n-r)! r!)
//                  (or)
// C(n,r) == C(n-1,r-1)+C(n-1,r); C(n,0) = C(n,n) = 1

#include <iostream>

using namespace std;

long long binomialCoefficientR(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    long long total = binomialCoefficientR(n - 1, r - 1) + binomialCoefficientR(n - 1, r);
    return total;
}

long long C[100][100];
long long binomialCoefficientDP(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    if (C[n][r] != 0)
        return C[n][r];

    long long total = binomialCoefficientDP(n - 1, r - 1) + binomialCoefficientDP(n - 1, r);
    C[n][r] = total;

    return total;
}

int binomialCoefficient(int n, int r)
{
    int nFact = 1;
    int rFact = 1;
    int nrFact = 1;

    for (int i = 1; i <= n; i++)
        nFact *= i;

    for (int i = 1; i <= r; i++)
        rFact *= i;

    for (int i = 1; i <= (n - r); i++)
        nrFact *= i;

    return nFact / (nrFact * rFact);
}

int main()
{
    while (true)
    {
        int n, r;
        cin >> n;
        cin >> r;
        cout << "dynamic => " << binomialCoefficientDP(n, r) << "\n";
        cout << "recursion => " << binomialCoefficientR(n, r) << "\n";
        cout << "formula => " << binomialCoefficient(n, r) << "\n";
    }
}