#include <iostream>

using namespace std;

int sameCandyAmount(int candies[], int count);

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        int candies[n];
        if (n == -1)
            break;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            candies[i] = c;
        }
        cout << sameCandyAmount(candies, n) << "\n";
    }

    return 0;
}

int sameCandyAmount(int candies[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += candies[i];

    if (sum % count != 0)
        return -1;

    int avg = sum / count;

    int movesNeeded = 0;
    for (int i = 0; i < count; i++)
        if (candies[i] < avg)
            movesNeeded += (avg - candies[i]);

    return movesNeeded;
}