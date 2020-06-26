#include <bits/stdc++.h>
#include <time.h>

using namespace std;

bool isPrime(long p)
{
    for (int i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int start = clock();
    long long n = 600851475143;
    for (long i = sqrt(n); i > 0; i--)
    {
        if (n % i == 0 && isPrime(i))
        {
            cout << i <<"\n";
            break;
        }
    }
    int end = clock();
    cout << ((float)end - start) / CLOCKS_PER_SEC << "seconds.";
    return 0;
}
