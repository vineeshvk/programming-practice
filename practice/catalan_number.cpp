#include <iostream>

using namespace std;

int catalan(int n)
{
    if (n < 2)
        return 1;

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += catalan(i) * catalan(n - 1 - i);
    }
    return total;
}

int memory[1000];
long long  catalanDP(long long  n)
{
    if (n < 2)
        return 1;

    if (memory[n] != 0)
    {
        return memory[n];
    }

    long long total = 0;
    for (long long  i = 0; i < n; i++)
    {
        total += catalanDP(i) * catalanDP(n - 1 - i);
    }

    memory[n] = total;
    return total;
}

int main()
{

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    cout << catalanDP(i) << "\n";

    cout << catalan(n) << "\n";
    return 0;
}