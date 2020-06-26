//will always be 0 if the N > 4 
#include <bits/stdc++.h>
using namespace std;
int fact[100000];
long long factorial(long long N)
{
    if (N < 2)
        return 1;
    if (fact[N] != 0)
        return fact[N];
    long long val = N * factorial(N - 1);
    fact[N] = val;

    return val;
}

int main()
{
    int t;
    cin >> t;
    for (int ts = 0; ts < t; ts++)
    {
        long long N, M;
        cin >> N >> M;
        long long mod = 1;
        for (int i = 0; i < M; i++)
            mod *= 10;
        
        cout << (factorial(factorial(N)) % 10) << "\n";
    }

    return 0;
}