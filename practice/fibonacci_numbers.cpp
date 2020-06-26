#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long memory[1000];
int fibonacciDP(int n)
{
    if (n <= 1)
        memory[n] = n;

    if (memory[n] != -1)
        return memory[n];

    memory[n] = fibonacciDP(n - 1) + fibonacciDP(n - 2);
    return memory[n];
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        memory[i] = -1;
    }
    int n;
    cout << "ds";
    cin >> n;
    cout << fibonacciDP(n) << "\n";
    cout << fibonacci(n) << "\n";
}