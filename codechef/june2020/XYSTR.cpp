#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++)
    {
        string row;
        cin >> row;
        char ls = 'o';
        int pairs = 0;
        for (char st : row)
        {
            if ((st == 'x' && ls == 'y') || (st == 'y' && ls == 'x'))
            {
                pairs++;
                ls = 'o';
            }
            else
            {
                ls = st;
            }
        }
        cout << pairs << "\n";
    }
}