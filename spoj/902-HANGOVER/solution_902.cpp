#include <iostream>

using namespace std;

int minCardsRequired(float c)
{
    int n = 1;
    float sum = 1.0 / 2.0;

    while (sum < c)
    {
        sum += 1.0 / (n + 2.0);
        n++;
    }
    return n;
}

int main()
{
    while (true)
    {
        float c;
        cin >> c;

        if (c == 0.00)
            return 0;

        cout << minCardsRequired(c) << " card(s)"<< "\n";
    }
}