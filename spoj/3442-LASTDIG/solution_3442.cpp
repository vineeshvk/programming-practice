#include <iostream>
using namespace std;

int lDigit(int n, long long p)
{
    if (p == 0)
        return 1;
    int d = n % 10;

    if (d == 5 || d == 0 || d == 6 || d == 1)
        return d;
    bool isEven = p % 2 == 0;
    if (d == 4)
        return isEven ? 6 : 4;
    if (d == 9)
        return isEven ? 1 : 9;

    int p4 = p % 4;
    p4 = p4 == 0 ? 4 : p4;
    int ldig = 1;
    for (int i = 1; i <= p4; i++)
        ldig = (d * ldig) % 10;
    return ldig;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        long long p;
        cin >> n >> p;
        cout << lDigit(n, p) << "\n";
    }
    return 0;
}