#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    while (n % 2 == 0)
        n /= 2;

    cout << (n == 1 ? "TAK" : "NIE");
    return 0;
}