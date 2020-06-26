#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long k;
        cin >> k;
        cout << 192 + ((k - 1) * 250) << "\n";
    }
    return 0;
}