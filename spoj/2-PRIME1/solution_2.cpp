#include <iostream>

using namespace std;

void primeNumber(int, int);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n;
        cin >> m;
        cin >> n;
        primeNumber(m, n);
        cout << "\n";
    }

    return 0;
}

void primeNumber(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        bool odd = i % 2 != 0;
        int n = odd ? 3 : 2;
        bool prime = i != 1;
        while (n * n <= i && prime)
        {
            prime = i % n != 0;
            n+=2;
        }

        if (prime)
            cout << i << "\n";
    }
}