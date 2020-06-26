#include <iostream>

using namespace std;

int main()
{
    int fibo[1000];
    fibo[0] = 1;
    fibo[1] = 2;

    int lastVal = 1;
    long long sum = 2;
    for (int i = 2; lastVal <= 4000000; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        lastVal = fibo[i];

        if (lastVal % 2 == 0)
            sum += lastVal;
    }
    cout << sum;
}