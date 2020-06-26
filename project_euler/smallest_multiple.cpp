#include <bits/stdc++.h>

using namespace std;

void sieve_prime(int n, int isPrime[])
{

    for (int p = 2; p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }
}

int main()
{
    int n = 20;

    int isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));

    sieve_prime(n, isPrime);
    int num = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            int ex = 2;
            num *= i;
            while (pow(i, ex) <= n)
            {
                num *= i;
                ex++;
            }
        }
    }
    cout << num << "\n";

    return 0;
}