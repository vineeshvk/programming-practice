#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long p)
{
    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

int primeNumber(int n)
{
    int count = 0;
    int i = 2;
    while (count != n)
    {
        if (isPrime(i))
            count++;

        i++;
    }

    return i - 1;
}

int main()
{
    cout << primeNumber(10001);
    return 0;
}