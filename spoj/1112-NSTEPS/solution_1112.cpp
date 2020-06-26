#include <iostream>

using namespace std;

int numberStep(int x, int y);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int val = numberStep(x, y);
        if (val == -1)
            cout << "No Number";
        else
            cout << val;
        cout << "\n";
    }
    return 0;
}

int numberStep(int x, int y)
{
    int val = x + y;
    bool condition = (x - y) <= 2 && x >= y;

    if (x % 2 == 0 && y % 2 == 0 && condition)
        return val;
    if (x % 2 != 0 && y % 2 != 0 && condition)
        return val - 1;
    return -1;
}