#include <iostream>
using namespace std;

int rev_number(int n)
{
    int rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main()
{
    int tests;
    cin >> tests;
    cout << (char)tests;
    return 0;
    for (int t = 0; t < tests; t++)
    {
        int n;
        cin >> n;
        cout << rev_number(n) << "\n";
    }
    return 0;
}