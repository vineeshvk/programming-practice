#include <bits/stdc++.h>
using namespace std;

bool isdigit_s(string num)
{
    int i = 0;
    while (isdigit(num[i]) && i < num.size())
        i++;
    if (i == num.size())
        return true;
    return false;
}

int main()
{
    int tests;
    cin >> tests;

    for (int t = 0; t < tests; t++)
    {
        string exp[5];

        for (int i = 0; i < 5; i++)
            cin >> exp[i];

        string num1 = exp[0], num2 = exp[2], result = exp[4];
        if (!isdigit_s(num1))
        {
            int n1 = stoi(result) - stoi(num2);
            cout << n1 << " + " << num2 << " = " << result;
        }
        else if (!isdigit_s(num2))
        {
            int n2 = stoi(result) - stoi(num1);
            cout << num1 << " + " << n2 << " = " << result;
        }
        else
        {
            int rs = stoi(num1) + stoi(num2);
            cout << num1 << " + " << num2 << " = " << rs;
        }
        cout << "\n";
    }
    return 0;
}
