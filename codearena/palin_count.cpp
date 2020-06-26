#include <bits/stdc++.h>
using namespace std;

string nextPalin(string n)
{
    int size = n.size();
    int half = (size - 1 )/ 2;
    string temp = n;

    for (int i = 0; i <= half; i++)
        n[size - i - 1] = n[i];

    if (n > temp)
        return n;

    for (int i = half; i >= 0; i--)
    {
        if (n[i] != '9')
        {
            n[i]++;
            break;
        }
        n[i] = '0';
    }
    for (int i = 0; i <= half; i++)
        n[size - i - 1] = n[i];

    if (n[0] == '0')
    {
        n[size - 1] = '1';
        n = "1" + n;
    }
    return n;
}

int main()
{
    int t;
    // cin >> t;
    for (int ts = 0; ts < 1; ts++)
    {
        int a, b;
        a = 9;
        b = 100000;
        string val = to_string(a);
        int count = 0;
        for (int i = a - 1; i <= b; i++)
        {
            val = nextPalin(val);
            int vi = stoi(val);
            if (vi > b)
                break;
            count++;
        }
        cout << count << "\n";
    }
    return 0;
}