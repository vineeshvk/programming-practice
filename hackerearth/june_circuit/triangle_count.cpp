#include <bits/stdc++.h>

using namespace std;

int mem[10000];
int factorial(int n)
{
    if (mem[n] != -1)
        return mem[n];
    mem[n] = n * factorial(n - 1);
    return mem[n];
}

int main()
{
    int test = 1;
    cin >> test;

    memset(mem, -1, sizeof(mem));
    mem[0] = 1;
    mem[1] = 1;

    for (int t = 0; t < test; t++)
    {
        int n;
        cin >> n;

        int b1, b2;

        cin>> b1>> b2;
        cout << factorial(n - 2) << " ";
    }
}
