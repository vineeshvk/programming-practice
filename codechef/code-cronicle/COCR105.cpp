#include <iostream>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int t = 0; t < test; t++)
    {
        int L, R;
        cin >> L >> R;
        R = R == 0 ? 24: R;
        cout << ((R - L) * 2) << "\n";
    }
    return 0;
}