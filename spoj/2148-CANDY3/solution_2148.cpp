/* 
using modular arithmetic
1+2+3+4 = 10 % 4 == 2
1%4+2%4+3%4+4%4 = 6 % 4 = 2
*/
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long candies;
            cin >> candies;
            sum += (candies % n);
        }
        if (sum % n == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
    return 0;
}