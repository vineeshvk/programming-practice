#include <iostream>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        int n;
        cin >> n;
        int fiveCoins = 0, tenCoins = 0, fifteenCoins = 0;
        bool canGiveChange = true;
        for (int i = 0; i < n; i++)
        {
            int money;
            cin >> money;

            if (money == 5)
            {
                fiveCoins++;
            }
            else if (money == 10)
            {
                if (fiveCoins < 1)
                    canGiveChange = false;
                tenCoins++;
                fiveCoins--;
            }
            else
            {
                if (tenCoins >= 1)
                    tenCoins--;
                else if (fiveCoins >= 2)
                    fiveCoins -= 2;
                else
                    canGiveChange = false;
                fifteenCoins++;
            }
        }
        cout << (canGiveChange ? "YES" : "NO") << "\n";
    }
    return 0;
}