#include <bits/stdc++.h>

using namespace std;

void primeNumber(long long n)
{
    int isPrime[n + 1];

    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i < sqrt(n); i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << " ";
}

int main()
{
    primeNumber(1000);
    return 0;
}