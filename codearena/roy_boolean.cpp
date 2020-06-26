#include <bits/stdc++.h>
using namespace std;

bool isDivided(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (num % arr[i] == 0)
            return true;
    }
    return false;
}

bool sieve_prime(long long n)
{
    bool prime[100000];
    memset(prime, true, n + 1);
    prime[0] = false;
    prime[1] = false;

    for (long long i = 2; i * i <= n; i++)
    {
        if (prime[i])
            for (long long p = i * i; p <= n; p += i)
                prime[p] = false;
    }

    long long count = 1;
    int val[n + 1], vi = 0;
    for (long long i = 2; i < n; i++)
    {
        if (n % i != 0)
        {
            if (vi != 0 && isDivided(val, vi, i))
                continue;
            count++;
        }
        else
            val[vi++] = i;
    }

    return prime[count];
}

int main()
{
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        long long n;
        cin >> n;
        cout << (sieve_prime(n) ? "TRUE" : "FALSE") << "\n";
    }
    return 0;
}