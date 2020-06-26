#include <iostream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        int n;
        cin >> n;

        bool isEven = n % 2 == 0;
        int oi = 0, ei = 1;
        for (int i = 0; i < n; i++)
        {
            if (n % 2 == 0)
                isEven = !isEven;
            for (int j = 0; j < n; j++)
            {
                cout << (isEven ? (2 * ei++) : (2 * oi++ + 1)) << " ";
                isEven = !isEven;
            }
            cout << "\n";
        }
    }

    return 0;
}