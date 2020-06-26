#include <iostream>

using namespace std;

int noOfSquares(int N);
// not in python
int main()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;
        cout << noOfSquares(N) << "\n";
    }

    return 0;
}

int noOfSquares(int N)
{
    int total = 1;
    for (int i = 2; i <= N; i++)
        total += i * i;
    return total;
}