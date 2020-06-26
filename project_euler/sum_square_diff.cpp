#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 10;
    int sumSquare = 0;
    for (int i = 0; i <= n; i++)
        sumSquare += i * i ; // formula n * (n + 1) * ( 2n  + 1) / 6
    int squareSum = (n * (n + 1)) / 2;
    squareSum *= squareSum;

    cout << sumSquare;
    return 0;
}