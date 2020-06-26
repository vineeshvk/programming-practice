#include <iostream>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int n, k;
        cin >> n >> k;
        int loss = 0;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            if (val > k)
                loss += (val - k);
        }
        cout << loss << "\n";
    }
    return 0;
}